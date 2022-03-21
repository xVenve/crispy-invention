/* --------------------------
Entry: 0020
WWW: http://
Title: The Old Fractal
Author: Georg Mogk
---------------------------*/

// PoVRay 3.5 Scene File " The Old Fractal .pov"
// Date:   15.04.2004
//--------------------------------------------------------------------------
#version 3.5;
global_settings {  assumed_gamma 1.0 }
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"   
                                            
                                            
                                            
//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
camera {//ultra_wide_angle angle 75          // front view
                            location  <0.0 , 0.2 ,-1.6>
                            right     x*image_width/image_height
                            look_at   <0.0 , 0.5 , 0.0>
                            }
// sun ---------------------------------------------------------------------
light_source{<1500,2500,-2500> color <1,1,1>}
// sky ---------------------------------------------------------------------
plane{<0,1,0>,1 hollow  
       texture{pigment{ bozo turbulence 0.85 scale 1.0 translate<5,0,0>
                        color_map { [0.5 rgb <0.20, 0.20, 1.0>]
                                    [0.6 rgb <1,1,1>]
                                    [1.0 rgb <0.5,0.5,0.5>]}
                       }
               finish {ambient 1 diffuse 0} }      
       scale 10000}
//------------------------------
fog{distance 300000 color <1,1,1>}            
//----------------------- Materials --------------------------------------------- 
#declare Wing = blob {
  threshold 0.56
  cylinder {<-1,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>}
    
  cylinder {<-0.875,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>
    rotate y*-4
    translate -z*0.375}
     
  cylinder {<-0.75,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>
    rotate y*-8
    translate -z*0.75}
    
  cylinder {<-0.625,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>
    rotate y*-12
    translate -z*1.125}
    
  texture {
    pigment { bozo
      color_map {
        [0 rgb <0.7,0.63,0.58>] 
        [0.5 rgb <0.4,0.4,0.4>]
        [1 rgb <1,0.8,0.6>]
        }
      turbulence 0.3
      }
    scale <1,0.1,0.1>
    rotate y*-30
    }
  }  // end Wing  
  
#declare Wingtip = blob {
  threshold 0.56
  cylinder {<-0.5,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>}
    
  cylinder {<-0.375,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>
    rotate y*-15
    translate <-0.125,0,-0.375>}
     
  cylinder {<-0.375,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.312>
    rotate y*-30
    translate <-0.25,0,-0.75>}
    
  cylinder {<-0.375,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.25>
    rotate y*-50
    translate <-0.375,0,-1.125>}
    
  texture {
    pigment { bozo
      color_map {
        [0 rgb <0.7,0.63,0.58>] 
        [0.5 rgb <0.4,0.4,0.4>]
        [1 rgb <1,0.8,0.6>]
        }
      turbulence 0.3
      }
    scale <1,0.1,0.1>
    rotate y*-30
    }
  }  // end Wingtip
              
#declare Rust =
texture { 
    pigment {
        granite
        color_map {
            [0.0 rgb <0.89, 0.51, 0.28>]
            [0.4 rgb <0.70, 0.13, 0.00>]
            [0.5 rgb <0.69, 0.41, 0.08>]
            [0.6 rgb <0.49, 0.31, 0.28>]
            [1.0 rgb <0.89, 0.51, 0.28>]
        }
    }
    finish { ambient 0.2 diffuse 0.4 }
}
#declare F_MetalA  =
finish {
    ambient 0.35
    brilliance 2
    diffuse 0.3
    metallic
    specular 0.80
    roughness 1/20
    reflection 0.1
};
#declare P_Copper1   = color rgb <0.40, 0.20, 0.15>;
#declare T_Copper_1A = texture { pigment { P_Copper1 } finish { F_MetalA  } }
//---------------------- Basic Definitions ---------------------------------------
#declare a=1/sqrt(3);
#declare b=1/(2*sqrt(3));
#declare c=0.5;
#declare h=sqrt(2/3);    
#declare R=sqrt(6)/4;     
#declare d=1-R;                 
 
 
// Vertexes of Tetraheadron
#declare TetraEcken = array[4];
#declare TetraEcken[0] = <-c,-d,-b>;
#declare TetraEcken[1] = <c,-d,-b>;
#declare TetraEcken[2] = <0,-d,a>;
#declare TetraEcken[3] = <0,R,0>;
#declare Dodecahedron = 
 intersection 
  {plane {-z, 1 rotate <-26.56505117708,    0, 0>}
   plane {-z, 1 rotate <-26.56505117708,  -72, 0>}
   plane {-z, 1 rotate <-26.56505117708, -144, 0>}
   plane {-z, 1 rotate <-26.56505117708, -216, 0>}
   plane {-z, 1 rotate <-26.56505117708, -288, 0>}
   
   plane {-z, 1 rotate <26.56505117708,  -36, 0>}
   plane {-z, 1 rotate <26.56505117708, -108, 0>}
   plane {-z, 1 rotate <26.56505117708, -180, 0>}
   plane {-z, 1 rotate <26.56505117708, -252, 0>}
   plane {-z, 1 rotate <26.56505117708, -324, 0>}
   
   plane { y, 1}
   plane {-y, 1}
   
   bounded_by {sphere {0, 1.2585}}
  }
                            
//-----------------------Macros--------------------------------------  
#macro Bird (F)

#declare Flap = sin(F*2*pi);
#declare Tipflap = sin(F*2*pi-pi/2); // 90° lag

union {
  union {  // right wing
    object { Wingtip
      rotate <-15+35*Tipflap,-24,0>
      translate -z*1.25
      }
    object { Wing }
    rotate <60*Flap,-7,10>
    translate <0.5,0.438,-0.625>
    } 
  union {  // left wing
    object { Wingtip
      rotate <15-35*Tipflap,-24,0>
      translate -z*1.25
      }
    object { Wing }
    rotate <180-60*Flap,7,10>
    translate <0.5,0.438,0.625>
    }
  sphere {0,1 // right eye
    scale <0.094,0.094,0.04>
    rotate x*10
    translate <1.875,0.812,-0.344>
    texture {
      pigment { color rgb 0.1}
      finish { phong 1 phong_size 100 }
      }
    }
 sphere {0,1 // left eye
    scale <0.094,0.094,0.04>
    rotate x*-10
    translate <1.875,0.812,0.344>
    texture {
      pigment { color rgb 0.1}
      finish { phong 1 phong_size 100 }
      }
    }
  blob {
    threshold 0.56
    sphere {<0,0,0>,1,1 // body
      scale <3,1.5,1.5>
      rotate z*10
      }
    sphere {<0,0,0>,1,1 // tail
      scale <1.5,0.25,0.75>
      rotate z*15
      translate <-1.75,0,0>
      }
    sphere {<0,0,0>,1,1 // head
      scale <1,0.625,0.625>
      rotate <0,0,-15>
      translate <1.75,0.75,0>
      }
    cylinder {<0,0,0>,<0.25,0,0>,1,1 // beak
      scale <1,0.25,0.125>
      rotate <0,0,-15>
      translate <2,0.625,0>
      texture { pigment { color rgb <1,0.8,0>}}
      }
    }    // end blob
  texture {
    pigment { bozo
      color_map {
        [0 rgb <0.7,0.63,0.58>] 
        [0.5 rgb <0.4,0.4,0.4>]
        [1 rgb <1,0.8,0.6>]
        }
      turbulence 0.3
      }
    scale <2,0.1,0.1>
    rotate z*10
    }
  translate -y*Flap*0.25
  }   // end union
#end  // end Bird                 
#declare Dodekaeder =                                                                         
object{ Dodecahedron bounded_by{box{<-1.5,-1.5,-1.5>,<1.5,1.5,1.5>}}
        scale <1,1,1>*0.75  rotate<25,25,0> //translate<0,1,0>
       }; // end of object;
       
#macro Linie (P1,P2,dick)
        // create a curved tube object translating a sphere along a certain path
        sphere_sweep {
          linear_spline                 
          2,                            // number of specified sphere positions
          P1, dick                // position, radius
          P2, dick                 // ...
          tolerance 0.001             // optional
        }
#end //Macro    
#macro TetraederBaum(itlevel, Atom,sf)
    union{
                object{
                       Atom
                       scale sf
                       } 
           #if (itlevel>0)
           #local num=0; 
           #while (num < 4)
                object{
                  union{     
                        Linie (<0,0,0>, 0.5*TetraEcken[num],0.02)
                        object{
                                TetraederBaum(itlevel-1,Atom,sf)
                                scale sf
                                translate 0.5*(TetraEcken[num])
                        }
                       }  
                    }
                #local num = num +1;
           #end // while    
          #end // if   
        }  // union  
#end // Ende des Macros       


#macro WooblyTree(woodBaseX,woodBaseY,woodBaseZ,woodEnd,rad,it) 
union{
    object{
      TetraederBaum(it,sphere { <0, 0, 0>,0.5},<0.5, 0.5, 0.5>)
       pigment{DarkGreen}
      rotate y*-30
      translate <woodBaseX,woodEnd,woodBaseZ>
     }         
     cylinder {
        <woodBaseX,woodBaseY,woodBaseZ>,<woodBaseX,woodEnd,woodBaseZ>,rad
        texture {DMFDarkOak }
      }
    }no_shadow
#end

         
//-------------------- Scene --------------------------------------------------------       
// sea ---------------------------------------------------------------------
plane{<0,1,0>, 0 
       pigment{ color rgb<0.6,1,0>}
    normal { agate 1.0      // bump depth
         agate_turb 2.0 // default 1 !!!
         scale 0.5 
    }}          

#object{                         
    WooblyTree(0,0,0,0.7,0.08,3)
    translate<0.25,0,1>
    
}  
#object{                         
    WooblyTree(0.55,0,0,0.7,0.08,3)
    
}  
#object{
    WooblyTree(0.4,0,0.5,0.7,0.08,3)       
}          

#object{                       
    WooblyTree(0,0,0,0.7,0.08,3) 
    rotate<0,90,0> 
    translate<-0.5,0,1>
} 

#object{                       
    WooblyTree(0,0,0,0.7,0.08,3) 
    rotate<0,90,0> 
    translate<-0.65,0,0.5>
} 
       
#object{                       
    WooblyTree(0,0,0,0.7,0.08,3) 
    rotate<0,90,0> 
    translate<-0.7,0,0>
} 


   
   
#object { Bird (clock)
  rotate y*10     
  scale 0.05
  translate<0,1.2,0>
}

object { Bird (clock)
  rotate y*10     
  scale 0.05
  translate<-0.5,1,0>
}   

object { Bird (clock)
  rotate y*10     
  scale 0.05
  translate<-0.4,1.3,0>
}                       
  
                  