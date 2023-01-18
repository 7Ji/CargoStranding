#ifndef _HAVE_REQUEST_H
#define _HAVE_REQUEST_H

#include <vector>

#include <material.hpp>

class Request {
  public:
    Material::Types type;
    uint quantity;
    std::vector <Material> materials;

    Request(Material::Types type, uint quantity);
};

#endif