#include "colors.inc" 
#include "textures.inc"

camera {
	location <0,15,-20>
	look_at <0,5,5> 
}

light_source {
	<25, 25, -25>
	color rgb <1, 1, 1>
}

// Botella generada con SOR

sor {6,
	<0,0>, <3,0>, <3,10>, <1,12>, <1,14>, <0,14>
	open
	//pigment { color Blue }
	texture {Glass3} 
}


// Botella genera con LATHE
// Probar a reemplazar el tipo de spline: linear_spline   quadratic_spline   cubic_spline

//lathe {
//	linear_spline
//	6,
//	<0,0>, <3,0>, <3,10>, <1,12>, <1,14>, <0,14>
//	pigment { color Blue }
//	//texture {Glass3} 
//}

background { color Red
}