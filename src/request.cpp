#include <iostream>
#include <cstring>

#include <request.hpp>


void Request::update_weight_string() {
    uint weight_int = weight / 10;
    uint weight_decimal = weight - weight_int * 10;
    int r = std::snprintf(weight_string, 7, "%u.%u", weight_int, weight_decimal);
    if (r > 6) { // truncated
        std::strncpy(weight_string, "------", 7);
    } else if (r < 0) { // error
        std::strncpy(weight_string, "xxxxxx", 7);
    }
}

Request::Request(Material::Types type, uint quantity) {
    this->type = type;
    this->quantity = quantity;

    weight = 0;
    volume = 0;

    while (quantity) {
        materials.push_back(Material(type, quantity));
        Material &last = materials.back();
        weight += last.weight;
        volume += last.volume;
        if (last.quantity >= quantity) {
            break;
        }
        quantity -= last.quantity;
    }
    update_weight_string();
}

void Request::list() {
    uint last_quantity = 0;
    uint same_quantity = 0;
    for (Material &material : materials) {
        if (last_quantity == material.quantity) {
            ++same_quantity;
        } else {
            if (same_quantity) {
                std::printf("%u\n", same_quantity);
            }
            same_quantity = 1;
            last_quantity = material.quantity;
            std::printf("    -> %s (%s, %skg) * ", material.name, material.size_string, material.weight_string);
        }
    }
    if (same_quantity) {
        std::printf("%u\n", same_quantity);
    }
    std::printf("    -> Total weight: %skg, total volume: %u\n", weight_string, volume);
}