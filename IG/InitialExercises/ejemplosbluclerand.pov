#include "colors.inc"
#include "textures.inc"

camera {
location <5,5,-20> look_at <5.0, 5.0, 0.0>
}

light_source {
<-10, 10, -10> color Blue
}

light_source {
<0, 20,-3> color Orange
}

#declare RandomSeed = seed(777);

// Esto se puede hacer más elegantemente con macros
#declare MiEsfera =
	sphere {<0, 0, 0>, 0.85 
	}	

// Ejemplo bucle while
 #local Cntr = 1; // start
 #while ( Cntr <= 5 )
	 object{ MiEsfera
	 		pigment { color Yellow }
	 		scale 0.8+0.4*rand(RandomSeed)
	 		translate<Cntr*3,0,0>
	 		finish {phong 1}
	         } // end of object
	
	 #local Cntr = Cntr + 1; 
 #end 

// Ejemplo blucle for
//#for (Iterador, Inicio, Final [, Step])
 #for (Cntr, 1, 5, 1)
	   object{ MiEsfera
			pigment { color Green }
			translate<0,Cntr*2+rand(RandomSeed)*.25,0 >
			finish {phong 1}
	         } // end of object
 #end

