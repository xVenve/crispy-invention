#include "colors.inc" 
#include "textures.inc"

camera {
	location <0,15,-10>
	look_at <0,5,0> 
}

light_source {
	<25, 25, -25>
	color rgb <1, 1, 1>
}

// Prisma generado por extrusión
  prism {
    linear_sweep  // También puede configurarse para que tome forma de pirámide conic_sweep
    linear_spline  // Tipo de función para unir los puntos ( quadratic_spline, cubic_spline… ojo puntos de control) 
    0, // Base
    8, // Altura
    13, // Puntos de la base
    <1,-2>, <1,-1>, <2,-1>, <2,1>, <1, 1>, <1,2>, <-1,2>,  <-1, 1>,  <-2, 1>,  <-2, -1>,  <-1,-1>,  <-1, -2>,  <1, -2>
    pigment { Blue}
//	texture {Glass3} 
  }


background { color Red
}