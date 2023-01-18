#include <cstring>
#include <iostream>

#include <cargo.hpp>

void Cargo::update_size_string() {
    size_string = size_strings[size];
}

void Cargo::set_size(Sizes size) {
    length = lengths[size];
    height = heights[size];
    volume = volumes[size];
    this->size = size;
    update_size_string();
}

void Cargo::update_weight_string() {
    uint weight_int = weight / 10;
    uint weight_decimal = weight - weight_int * 10;
    int r = snprintf(weight_string, 7, "%u.%u", weight_int, weight_decimal);
    if (r > 0) { // truncated
        strncpy(weight_string, "------", 7);
    } else if (r < 0) { // error
        std::strncpy(weight_string, "xxxxxx", 7);
    }
}

void Cargo::set_weight(uint weight) {
    this->weight = weight;
    update_weight_string();
}

void Cargo::set_size_and_weight(Sizes size, uint weight) {
    set_size(size);
    set_weight(weight);
}