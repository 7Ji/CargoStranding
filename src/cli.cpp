#include <cstring>
#include <iostream>

#include <cli.hpp>

void Cli::help() {
    std::puts(
        "=> Metarial Types:\n"
        "  => R/r for resins\n"
        "  => M/m for metals\n"
        "  => C for ceramics\n"
        "  => c for chemicals\n"
        "  => S/s for special alloys\n"
        "=> Please enter the material in the following format, one material per line:\n"
        "  => [type]count for exact count of materials you need\n"
        "    -> e.g. C100 for 100 ceramics\n"
        "  => [type]submitted/total for exact count of materials to complete the total\n"
        "    -> e.g. M100/2310 for a 2310 metal construction where you've already submitted 2310\n"
        "  => (above formats)*[number] for duplicated requests\n"
        "    -> e.g. M200*10 for 10 200-metal requests\n"
        "=> Additional commands:\n"
        "  => list: to list added requests\n"
        "  => delete [id]: to delete a request\n"
        "  => clear: to delete all requests\n"
        "  => report: to report what should be carried for the submitted requests\n"
        "  => help: to print this message again\n"
        "  => exit: to exit"
    );
}

void Cli::do_list() {
    uint i = 0;
    uint last_quantity = 0;
    uint same_quantity = 0;
    for (Request &request : requests) {
        ++i;
        std::printf("  => Request %u: %s * %u\n", i, Material::type_strings[request.type], request.quantity);
        last_quantity = 0;
        same_quantity = 0;
        for (Material &material : request.materials) {
            if (last_quantity == material.quantity) {
                ++same_quantity;
            } else {
                if (same_quantity) {
                    std::printf("%u\n", same_quantity);
                }
                same_quantity = 1;
                last_quantity = material.quantity;
                std::printf("    -> %s * ", material.name);
            }
        }
        if (same_quantity) {
            std::printf("%u\n", same_quantity);
        }
    }
}

int Cli::do_delete() {
    ulong id = std::strtoul(command + 7, NULL, 10);
    if (id == 0 || id > requests.size()) {
        std::printf("  => Request %lu does not exist!\n", id);
        return 1;
    }
    requests.erase(requests.begin() + id - 1);
    std::printf("  => Deleted request %lu\n", id);
    return 0;
}

void Cli::do_clear() {
    std::printf("  => Cleared %lu requests\n", requests.size());
    requests.clear();
}

void Cli::do_report() {
    uint summary[5][7] = {{0}};
    uint quantity_id;
    uint *summary_part;
    uint weight = 0;
    uint volume = 0;
    for (Request &request : requests) {
        summary_part = summary[request.type];
        for (Material &material : request.materials) {
            weight += material.quantity * Material::density;
            volume += material.volume;
            quantity_id = material.get_quantity_id();
            ++summary_part[quantity_id];
        }
    }
    std::puts(
        "  => Needed variants for current requests:\n"
        "==========================================================\n"
        " Type           |   S |   M |   L | XL1 | XL2 | XL3 | XL4 \n"
        "=========================================================="
    );
    uint const *quantity_group;
    uint material_cargos;
    for (uint i = 0; i < 5; ++i) {
        summary_part = summary[i];
        material_cargos = 0;
        for (uint j = 0; j < 7; ++j) {
            material_cargos += summary_part[j];
        }
        if (!material_cargos) {
            continue;
        }
        std::printf(" %-14s ", Material::type_strings[i]);
        quantity_group = Material::quantity_groups[i];
        for (uint j = 0; j < 7; ++j) {
            std::printf("|%4u ", quantity_group[j]);
        }
        std::printf("\n----------------+-----+-----+-----+-----+-----+-----+-----\n                ");
        for (uint j = 0; j < 7; ++j) {
            if (summary_part[j]) {
                std::printf("|%4u ", summary_part[j]);
            } else {
                std::printf("|     ");
            }
        }
        std::puts("\n==========================================================");
    }
    uint weight_int = weight / 10;
    uint weight_decimal = weight - weight_int * 10;
    std::printf("  => Total weight: %u.%u kg, total volume: %u\n", weight_int, weight_decimal, volume);
}

void Cli::do_exit() {
    std::exit(EXIT_SUCCESS);
}

int Cli::parse_command() {
    if (!std::strncmp(command, "list", 4)) {
        do_list();
        return 0;
    }
    if (!std::strncmp(command, "delete", 6)) {
        do_delete();
        return 0;
    }
    if (!std::strncmp(command, "clear", 5)) {
        do_clear();
        return 0;
    }
    if (!std::strncmp(command, "report", 6)) {
        do_report();
        return 0;
    }
    if (!std::strncmp(command, "help", 4)) {
        help();
        return 0;
    }
    if (!std::strncmp(command, "exit", 4)) {
        do_exit();
    }
    return -1;
}

int Cli::parse_request() {
    Material::Types type;
    switch(command[0]) {
        case 'R':
        case 'r':
            type = Material::Types::RESINS;
            break;
        case 'M':
        case 'm':
            type = Material::Types::METALS;
            break;
        case 'C':
            type = Material::Types::CERAMICS;
            break;
        case 'c':
            type = Material::Types::CHEMICALS;
            break;
        case 'S':
        case 's':
            type = Material::Types::SPECIAL_ALLOYS;
            break;
        default:
            return -1;
    }
    char *sep = nullptr;
    ulong quantity = std::strtoul(command + 1, &sep, 10);
    if (!quantity) {
        return -2;
    }
    if (*sep == '/') {
        ulong total = std::strtoul(sep + 1, &sep, 10);
        if (!total) {
            return -3;
        }
        quantity = total - quantity;
    }
    ulong duplicate = 1;
    if (*sep == '*') {
        duplicate = std::strtoul(sep + 1, nullptr, 10);
        if (!duplicate) {
            return -4;
        }
    }
    std::printf("  => Requested %s * %lu (%lu duplicates)\n", Material::type_strings[type], quantity, duplicate);
    for (ulong i = 0; i < duplicate; ++i) {
        requests.push_back(Request(type, quantity));
    }
    return 0;
}

int Cli::interact() {
    int r = 0;
    for (;;) {
        std::printf("=> Material request %lu or command: ", requests.size() + 1);
        std::cin.getline(command, 255);
        r = parse_command();
        if (r > 0) {
            return r;
        } else if (r < 0) {
            r = parse_request();
            if (r > 0) {
                return r;
            } else if (r < 0) {
                std::printf("  => Neither a valid request nor a valid command: %s\n", command);
            }
        }        
    }
    return 0;
}