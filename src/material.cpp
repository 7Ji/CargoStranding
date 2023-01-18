#include <iostream>

#include <material.hpp>

Material::Material(Types type, uint quantity_want) {
    this->type = type;
    uint const * const quantity_group = quantity_groups[type];
    uint i;
    for (i = 0; i < 7; ++i) {
        if (quantity_group[i] >= quantity_want) break;
    }
    if (i == 7) i = 6;
    quantity = quantity_group[i];
    Cargo::set_size_and_weight(sizes[i], quantity);
    std::snprintf(name, 32, "%s (%u)", type_strings[type], quantity);
}

uint Material::get_quantity_id() {
    uint const * const quantity_group = quantity_groups[type];
    for (uint i = 0; i < 7; ++i) {
        if (quantity_group[i] == quantity) {
            return i;
        }
    }
    return 0;
}