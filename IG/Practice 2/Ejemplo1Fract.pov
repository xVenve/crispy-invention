#include "textures.inc"


camera {
location <0,0,-3> look_at 0
}

sky_sphere { pigment { color rgb 1 } } 
light_source {< 20, 10, 50> color rgb <1,1,1> }

// Objeto base
#declare ring = torus { 1, 0.04 } 

// Monto la esfera de anillos
#declare ringsphere =
	union {
		object { ring }
		object { ring rotate <90,0,0> } 
		object { ring rotate <0,0,90> }
		
		texture {
		finish {Metal} 
		pigment {rgbt <0,1,0.0,0>} } //Transp 0-1	
}

// Declara el objeto fractal a partir de la esfera de anillos base
#declare fractal = ringsphere;

//object {
//	ringsphere
//	texture {
//	pigment {rgbt <0,0,1,0>} } //Transp 0-1
//}

////Ejemplo 1. Añado una copia 
//object { fractal scale 0.5 translate <0.5,0,0> }


////Ejemplo 2. Añado varias copias cada vez más pequeñas con un bucle
//#declare iteration = 0;
//#while (iteration<2)
//	#declare fractal = 
//		union {
//			object {ringsphere}
//			object {fractal scale 0.5 translate <0.5,0,0>}
//		}
//	#declare iteration= iteration + 1;
//#end


////Ejemplo 3. Añado varias copias cada vez más pequeñas con un bucle
//#declare iteration = 0;
//#while (iteration<1)
//	#declare fractal = 
//		union {
//			object {ringsphere}
//			object { fractal scale 0.5 translate <0.5,0,0> }
//			object { fractal scale 0.5 translate <-0.5,0,0> } 
//			object { fractal scale 0.5 translate <0,0.5,0> } 
//			object { fractal scale 0.5 translate <0,-0.5,0> } 
//			object { fractal scale 0.5 translate <0,0,0.5> } 
//			object { fractal scale 0.5 translate <0,0,-0.5> }
//		}
//	#declare iteration= iteration + 1;
//#end


//Instancio el objeto
object {fractal}


////Ejemplo 4. Programo lo mismo con macros
#macro myfractal (s, centro, recursividad)
	#if(recursividad>0)
	object { ringsphere scale s translate centro
		//rotate <20,30,40>
		texture { pigment {rgbt <0,1,0.0,0.3>} } 
		}
		myfractal (s/2, centro + 0.5*s*x,recursividad-1) 
		myfractal (s/2, centro + 0.5*s*-x,recursividad-1) 
		myfractal (s/2, centro + 0.5*s*y,recursividad-1) 
		myfractal (s/2, centro + 0.5*s*-y,recursividad-1) 
		myfractal (s/2, centro + 0.5*s*z,recursividad-1) 
		myfractal (s/2, centro + 0.5*s*-z,recursividad-1)
	#end 
#end
 myfractal (1, 0, 5)
