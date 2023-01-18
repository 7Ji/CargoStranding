#ifndef _HAVE_CARGO_H
#define _HAVE_CARGO_H

#include <common.hpp>

class Cargo {
  public:
    enum Sizes {
        S,
        M,
        L,
        XL
    };

    Sizes size;
    char const *size_string;
    static uint const width = 1;
    uint length;
    uint height;
    uint volume;
    uint weight; // 1 unit = 0.1 kg
    char weight_string[7]; // 1234.5
    char name[32];

    Cargo() {}

    void set_size(Sizes size);
    void set_weight(uint weight);
    void set_size_and_weight(Sizes size, uint weight);

  protected:
    void update_size_string();
    void update_weight_string();

  private:
    static char constexpr size_strings[4][3] = {
        "S",
        "M",
        "L",
        "XL"
    };
    static uint constexpr lengths[4] = {
        1, 2, 2, 2
    };
    static uint constexpr heights[4] = {
        1, 1, 2, 3
    };
    static uint constexpr volumes[4] = {
        1, 2, 4, 6
    };
};

#endif