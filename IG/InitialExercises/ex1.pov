#include "colors.inc"
camera {
    location <0, 0, 0>
    look_at <1, 1, 1>
}

light_source {
    <5,-5, 10>
    color rgb <1, 1, 1>
}

sphere {
    <10, 10, 10>, .8
    pigment { color Green }
}
