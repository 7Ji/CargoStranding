#ifndef _HAVE_REQUEST_H
#define _HAVE_REQUEST_H

#include <vector>

#include <material.hpp>

class Request {
  public:
    Material::Types type;
    uint quantity;
    uint weight;
    char weight_string[7];
    uint volume;
    std::vector <Material> materials;

    Request(Material::Types type, uint quantity);
    void list();
  
  protected:
    void update_weight_string();
};

#endif