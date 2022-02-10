#include "colors.inc"
#include "woods.inc“

camera {
    location <0,10,-30>
    look_at <0,5,20> 
}

light_source {
    <-20, 10, -20> color rgb <1, 1, 1>
}

union {
    box {
        <0, 0, 0> <10, 10, 10> texture {
        T_Wood9 }
    }
    cone {
        <-3, 0, 0>, 5, <-3, 10, 0>, 2 texture {
        T_Wood9 }
    }
    rotate <-30, 0, 0> 
}

background { color White}