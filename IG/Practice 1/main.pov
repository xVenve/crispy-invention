#include "colors.inc"
#include "textures.inc"
#include "woods.inc"

#declare bol = difference {
    union {
        sor {
            4,
            <0,0>,
            <.7,0>,
            <1.3,1.1>,
            <.8,3>
            pigment { color White }  
             finish {
              reflection {0.1} ambient 0.26 diffuse 1  
          }
          scale <0.9,0.8,0.8>
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
            finish {
              reflection {0.1} ambient 0.26 diffuse 1
          }
           scale <0.76,0.8,0.76>
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
         finish {
              reflection {0.1} ambient 0.26 diffuse 1
          } 
              scale <0.9,0.9,0.8>
    }
    translate <0,.4,0> 

 }

#declare ambientador = union {
    difference {
            box {
                <0,0,0><1.5,2,2>
                texture { T_Wood7 }
            }
            cylinder {
                <-1,1,1><3,1,1>,.67
                texture { T_Wood7 }
            }
            cylinder {
                <.75,.5,1><.75,1.5,1>,.5
            }
            cylinder {
                <.75,1,1><.75,3,1>,.3
                texture { T_Wood7 }
            }
            cylinder {
                <.75,.3,1><.75,1.7,1>,.501
            }
    }
    difference{
        cylinder {
            <.75,.3,1><.75,1.7,1>,.5
            texture { Glass3 }
        }
        cylinder {
            <.75,.3,1><.75,1.7,1>,.49
            texture { Glass3 }
        }
    }
    cylinder {
        <.75,.29,1><.75,.4,1>,.48
        pigment { color Green }
        texture { Glass }
    }
    difference {
        cylinder {
            <.75,1.7,1><.75,1.9,1>,.299
            texture { Glass3 }
        }
        cylinder {
            <.75,1.6,1><.75,3,1>,.25
            texture { Glass3 }
        }
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment { color rgb <0.85, 0.65, 0.13>}
        translate <.3,0.1,0>
        rotate <0,0,15>
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment { color rgb <0.85, 0.65, 0.13>}
        translate <.3,0.1,-.3>
        rotate <15,0,15>    
    }
    cylinder {
        <.75,0,1><.75,5,1>,.02
        pigment { color rgb <0.85, 0.65, 0.13>}
        translate <.3,-.3,.3>
        rotate <-17,0,15>    
    }
    translate <0,0,-1>
    rotate <0,105,0>
}

#macro picoFlorero(height)
    prism {
        linear_sweep
        linear_spline
        0,
        height,
        5,
        <-2,-3>, <-2,3>, <2,.8>, <2,-.8>, <-2,-3>
        texture {NBglass}
        finish { diffuse 2 } 
        rotate <0,-90,0>
        translate <0,0,7.2>
        scale .48
    }
#end

#declare hexagono = prism {
    linear_sweep
    linear_spline  
    .9,
    6.75,
    7,
    <0,0>, <4,0>, <6,2*sqrt(3)>, <4,4*sqrt(3)>, <0,4*sqrt(3)>, <-2,2*sqrt(3)>, <0,0>
    texture {NBglass}
    finish { diffuse 2 }  
    translate <-2,0,-2*sqrt(3)>
}

#declare florero = union {
    difference {
        object {
            hexagono
        }
        object {
            hexagono
            scale <.72,1.1,.72>
        }
        object {
        hexagono
        scale <.72,.16,.72>
        translate <0,-.15,0>
        }
        object {
            picoFlorero(17.8)
            rotate <0,0,0>
        }
        object {
            picoFlorero(16)
            rotate <0,60,0>
        }
        object {
            picoFlorero(18.5)
            rotate <0,120,0>
        }
        object {
            picoFlorero(17.8)
            rotate <0,180,0>
        }
        object {
            picoFlorero(18.5)
            rotate <0,240,0>
        }
        object {
            picoFlorero(16)
            rotate <0,300,0>
        }
    }
    object {
        hexagono
        scale <.72,.16,.72>
        translate <0,-.15,0>
    }
    object {
        picoFlorero(17.8)
        rotate <0,0,0>
    }
    object {
        picoFlorero(16)
        rotate <0,60,0>
    }
    object {
        picoFlorero(18.5)
        rotate <0,120,0>
    }
    object {
        picoFlorero(17.8)
        rotate <0,180,0>
    }
    object {
        picoFlorero(18.5)
        rotate <0,240,0>
    }
    object {
        picoFlorero(16)
        rotate <0,300,0>
    }
    rotate<0,60,0>
}

#declare RandomSeed = seed(16);
#declare esfera = difference {
    sphere {
        <0,0,0>,1
        pigment { color <1,0.549,0,.8> }
        texture { Glass3}
    }
    #local it = 0; // start
    #while ( it < 150 )
        sphere { 
            <rand(RandomSeed)*1.8-1,rand(RandomSeed)*1.8-1,rand(RandomSeed)*1.8-1>,.1*rand(RandomSeed)
            pigment { color <1,0.549,0,.8> }
            texture { Glass3}
        }
        #local it = it + 1; 
    #end 
    translate <0,1,0>
}

camera {
    location <0.2,4.6,14>
    look_at <0,0,0>
    right x
}


light_source {
    <0.8,10,-5.6>
    color White
}

object {
    bol
    translate <-0.9,0,8> 
      
}

object {
    ambientador 
    translate <0.4,0,5.8>
      
}

object {
    florero
    scale <.38,0.35,0.38>
    translate <2.4,0,3>
    

}

object {
    esfera
    scale 1.1
    translate <2.55,-0.05,7.2>
     interior{ior 1.2}
}        

 plane { <0,1, 0>, 0
   texture{
    pigment {
      color White
      }
     finish{reflection{0.1}
     }
    }           
   }
   
 plane { <-0.2,0, 1>, -8
   texture{
    pigment {
      color Black
      }
     }
    }  

// Bol por roc
// Cosa cristal por estrusion
// Perfume por difference
// Esfera es sphere con diff de esferas mas pequeñas, burbujas, usar bucle y numeros aleatorios