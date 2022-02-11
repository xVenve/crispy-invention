#include "colors.inc"
#include "textures.inc"

camera {
location <1,5,-5> look_at <0.0, 0.0, 0.0>
}

light_source {
<-10, 10, -10> color Blue
}

light_source {
<0, 0.5,-3> color Orange
}


//sphere {<1, 0, 0>, 2 
//	texture {Glass3}
//}
//
//sphere {<-1, 0, 0>, 2 
//	texture {Glass3}
//}


//Ejemplos  CSG. Probar union, difference, intersection y merge
union{
	sphere {<1, 0, 0>, 2 
	}	
	sphere {<-1, 0, 0>, 2 
	}
	texture {Glass3}
	//rotate <0,45,0>
}