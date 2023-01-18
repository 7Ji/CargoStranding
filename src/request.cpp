#include <request.hpp>

Request::Request(Material::Types type, uint quantity) {
    this->type = type;
    this->quantity = quantity;
    while (quantity) {
        materials.push_back(Material(type, quantity));
        Material &last = materials.back();
        if (last.quantity >= quantity) {
            break;
        }
        quantity -= last.quantity;
    }
}