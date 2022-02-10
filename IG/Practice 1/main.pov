#include "colors.inc"
#declare bol = sor {5,
	<0,.5>, <2,0>, <2.5,2>, <4,6>, <3,7>
	open
	pigment { color White }
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
    scale .6
}

// Bol por roc
// Cosa cristal por estrision
// Perfume por difference
// Esfera es sphere con diff de esferas mas pequeñas, burbujas, usar bucle y numeros aleatorios