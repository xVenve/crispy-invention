#include "colors.inc"
camera {
    location <-5, 1, -5>
    look_at <2,1,2>
}

light_source {
    <-1, -1, 0>
    color rgb <1, 1, 1>
}

sphere {
    <2, 1, 2>, 0.5
    pigment { color Green }
}
