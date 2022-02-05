#include "colors.inc"
camera {
    location <0, 1, 0>
    look_at <1, 1, 1>
}

light_source {
    <1,1,1>
    color rgb <1, 1, 1>
}

sphere {
    <3, 1.5, 3>, 1
    pigment { color Green }
}

plane {
    <0,1,0>, 0
    pigment { 
        checker color Blue color White}
}
