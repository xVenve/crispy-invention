#include "colors.inc"
camera {
    location <0, 1, 0>
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

plane {
    <0, 1, 0>, 0
    pigment { checker color Blue color White }
}
