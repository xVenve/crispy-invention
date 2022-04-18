#include "textures.inc"     
#include "colors.inc"
#include "glass.inc"       

global_settings{photons{count 5000
                        }
                }

light_source{<-10,50,40> color White
             photons{reflection on
                     refraction on}
            }

light_source{<-500,500,-400> color White
             photons{reflection on
                     refraction on}
            }
            
camera{location <0,4,-7>
       look_at <0,1,0>}

plane{y,0
      texture{pigment{rgb <.2,.2,.2>}
              finish {ambient 0.15
                      diffuse 0.55
                      brilliance 6.0
                      phong 0.8
                      phong_size 120
                      reflection 0.6}
              }
        normal{ bumps 0.05
         turbulence 0.6
       }      
              
      }

background{color rgb <0.3,0.3,1>}



merge{
	sphere {<1, 2.5, 0>, 1.5 
	}	
	sphere {<-1, 2.5, 0>, 1.5 
	}
	interior{ior 1.5}
	texture {Glass3
				finish {
				diffuse 0.6, 0.6
				brilliance 1.0
				phong 1.0
		}}

      photons{target
              reflection on
              refraction on
              collect on} 
}





