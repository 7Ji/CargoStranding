#ifndef _HAVE_MATERIAL_H
#define _HAVE_MATERIAL_H

#include <cargo.hpp>

class Material: public Cargo {
  public:
    enum Types {
        RESINS,
        METALS,
        CERAMICS,
        CHEMICALS,
        SPECIAL_ALLOYS
    };
    static char constexpr type_strings[5][15] = {
        "Resins",
        "Metals",
        "Ceramics",
        "Chemicals",
        "Special Alloys"
    };
    static uint const density = 1;
    static uint constexpr quantity_groups[5][7] = {
        {
            40, 80, 160, 320, 480, 640, 800
        }, 
        {
            50, 100, 200, 400, 600, 800, 1000
        }, 
        {
            40, 80, 160, 320, 480, 640, 800
        },
        {
            30, 60, 120, 240, 360, 480, 600
        },
        {
            60, 120, 240, 480, 720, 960, 1200
        }
    };
    Types type;
    uint quantity;

    Material(Types type, uint quantity_want);
    uint get_quantity_id();

  protected:
    static uint constexpr base_quantities[5] = {
        40, 50, 40, 30, 60
    };
    static uint constexpr quantity_multipliers[7] = {
        1, 2, 4, 8, 12, 16, 20
    };
    static Cargo::Sizes constexpr sizes[7] = {
        Cargo::Sizes::S,
        Cargo::Sizes::M,
        Cargo::Sizes::L,
        Cargo::Sizes::XL,
        Cargo::Sizes::XL,
        Cargo::Sizes::XL,
        Cargo::Sizes::XL
    };
};

#endif