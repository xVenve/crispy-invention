#include "colors.inc"
camera {
    location <-3, 1, -3>
    look_at <2, 1, 2>
}

light_source {
    <1, 4, 0>
    color rgb <1, 1, 1>
}

sphere {
    <2, 1, 2>, 0.5
    pigment { color Green }
}

box {
    <2, 0, 2>, <4, 3, 4>
    pigment { color Red }
}

plane {
    <1, 0, 1>, 8
    pigment { checker color Blue color White }
}