#include "colors.inc"
camera {
    location <7, 7, 7>
    look_at <8, 8, 8>
}

light_source {
    <5,5, -5>
    color rgb <1, 1, 1>
}

sphere {
    <10, 10, 10>, .8
    pigment { color Green }
}
