#include "colors.inc"
#declare bol = difference {
    union {
        sor {
            4,
            <0,0>,
            <.7,0>,
            <1.3,1.1>,
            <.8,3>
            pigment { color White }
        }
        sor {
            4,
            <0,0>,
            <.9,0>,
            <1.4,1.2>,
            <1,2.2>
            pigment { color White }
            rotate <180,0,0>
            translate <0,.5,0>
            scale .6
        }
    }
    sor {
        4,
        <0,0>,
        <.7,0>,
        <1.3,1.1>,
        <.8,3> 
        pigment { color White }
        scale .99
        translate <0,.1,0>
    }
    translate <0,.4,0>
 }

#declare ambientador = union {
    difference {
        difference {
            box {
                <0,0,0><1.5,2,2>
                pigment {color White}
            }
            cylinder {
                <-1,1,1><3,1,1>,.7
                pigment {color White}
            }
        }
        cylinder {
            <.75,1,1><.75,3,1>,.3
            pigment {color Orange}
        }
    }
    cylinder {
        <.75,.3,1><.75,1.7,1>,.5
        pigment {color Red}
    }
    cylinder {
        <.75,1.7,1><.75,1.9,1>,.3
        pigment {color Orange}
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment {color Orange}
        translate <0,3,0>
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment {color Orange}
        translate <0,3,1>
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment {color Orange}
        translate <0,3,2>
    }
}

camera {
    location <10,5,10>
    look_at <0,3,0>
}

light_source {
    <10,10,10>
    color White
}

object {
    bol
    scale 1
    translate <1,0,4>
}

object {
    ambientador
    scale 1
    translate <0,0,0>
}

// Bol por roc
// Cosa cristal por estrusion
// Perfume por difference
// Esfera es sphere con diff de esferas mas pequeñas, burbujas, usar bucle y numeros aleatorios