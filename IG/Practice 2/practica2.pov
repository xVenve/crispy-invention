#version 3.5;
global_settings { assumed_gamma 1.0 }
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"


camera {
    location <0.2 , 0.2 ,-1.6>
    right x*image_width/image_height
    look_at <0.0 , 0.5 , 0>
}

light_source {
    <1500,2500,-2500>
    color <1,1,1>
}

plane {
    <0,1,0>,1 hollow
    texture {
        pigment{
            bozo turbulence 0.85
            scale 1.0 
            translate<5,0,0>
            color_map {
                [0.5 rgb <0.20, 0.20, 1.0>]
                [0.6 rgb <1,1,1>]
                [1.0 rgb <0.5,0.5,0.5>]
            }
        }
        finish{
            ambient 1
            diffuse 0
        }
    }
    scale 10000
}

fog {
  distance 300000
  color <1,1,1>
}

//----------------------- Definición de materiales ---------------------------------------------
#declare Wing = blob {
  threshold 0.56

  cylinder {
    <-1,0,0>,<0,0,0>,1,1
    scale <1,0.188,0.375>
  }

    cylinder {
    <-0.875,0,0>,<0,0,0>,1,1
      scale <1,0.188,0.375>
      rotate y*-4
      translate -z*0.375
  }
     
    cylinder {
    <-0.75,0,0>,<0,0,0>,1,1
      scale <1,0.188,0.375>
      rotate y*-8
      translate -z*0.75
  }
    
    cylinder {
    <-0.625,0,0>,<0,0,0>,1,1
      scale <1,0.188,0.375>
      rotate y*-12
      translate -z*1.125
  }
    
    texture {
      pigment { 
      bozo
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
}
  
#declare Wingtip = blob {
    threshold 0.56
  
    cylinder {
    <-0.5,0,0>,<0,0,0>,1,1
      scale <1,0.188,0.375>
  }
    
    cylinder {
    <-0.375,0,0>,<0,0,0>,1,1
        scale <1,0.188,0.375>
        rotate y*-15
        translate <-0.125,0,-0.375>
  }
        
    cylinder {
        <-0.375,0,0>,<0,0,0>,1,1
        scale <1,0.188,0.312>
        rotate y*-30
        translate <-0.25,0,-0.75>
    }
        
    cylinder {
        <-0.375,0,0>,<0,0,0>,1,1
        scale <1,0.188,0.25>
        rotate y*-50
        translate <-0.375,0,-1.125>
    }
        
    texture {
        pigment { 
            bozo color_map {
                [0 rgb <0.7,0.63,0.58>]
                [0.5 rgb <0.4,0.4,0.4>]
                [1 rgb <1,0.8,0.6>]
                }
            turbulence 0.3
        }
        scale <1,0.1,0.1>
        rotate y*-30
    }
}

//---------------------- Definiciones Básicas  ---------------------------------------
#declare a = 1/sqrt(3);
#declare b = 1/(2*sqrt(3));
#declare c = 0.5;
#declare h = sqrt(2/3);    
#declare R = sqrt(6)/4;      
#declare d = 1-R;

//---------------------- Pigmentos y texturas ---------------------------------------
#declare Plaza_Texture =
    texture {
        pigment {
            granite
            turbulence 3
            color_map {
                [0.000 color rgb <0.5, 0.5, 0.2>]
                [0.25 color rgb <0.7, 1, 0.2>]
                [0.5 color rgb <1, 0.4, 0.2>]
                [0.75 color rgb <.5, 0.9, 0.2>]
                [1 color rgb <0.3, 0.9, 0.2>]
            }
            scale 0.035
        }
        finish { specular .25 }
        normal {
            average normal_map {
                [0.0 bumps 150 scale 30]
                [0.2 dents 50 scale 12.5 turbulence .3]
                [0.6 bump_map { gif "Assets/GBM4.gif" bump_size 2 } rotate x*90
                rotate y*45 scale 30 ]
                [1.0 wrinkles 25 scale 5 scallop_wave rotate z*30]
            }
            rotate z*15 turbulence 10
        }
    }


//---------------------- Fractal para el árbol ---------------------------------------
#declare TetraEcken = array[4];
#declare TetraEcken[0] = <-c,-d,-b>;
#declare TetraEcken[1] = <c,-d,-b>;
#declare TetraEcken[2] = <0,-d,a>;
#declare TetraEcken[3] = <0,R,0>;
#declare Dodecahedron = 
    intersection {
        plane {-z, 1 rotate <-26.56505117708,    0, 0> }
        plane {-z, 1 rotate <-26.56505117708,  -72, 0> }
        plane {-z, 1 rotate <-26.56505117708, -144, 0> }
        plane {-z, 1 rotate <-26.56505117708, -216, 0> }
        plane {-z, 1 rotate <-26.56505117708, -288, 0> }
        
        plane {-z, 1 rotate <26.56505117708,  -36, 0> }
        plane {-z, 1 rotate <26.56505117708, -108, 0> }
        plane {-z, 1 rotate <26.56505117708, -180, 0> }
        plane {-z, 1 rotate <26.56505117708, -252, 0> }
        plane {-z, 1 rotate <26.56505117708, -324, 0> }
        
        plane { y, 1 }
        plane {-y, 1 }
        
        bounded_by { sphere {0, 1.2585 } }
    }

//-----------------------Macros--------------------------------------
#declare stone = box {<0,0,0>,<2,1,5> texture { T_Grnt24 } }
#macro Fountain(itlevel)
    union { 
    #local num=1;
    #local s=.05;
    #local s2=.3;
    #while (num < itlevel)
    union {  
        #local t1=24;
        #local t2=0;
        #while (t2 < t1)
            object { stone translate<3,(num-1)*s2,0> scale <1-s*num,1,1-s*num> rotate<0,360-(t2*360/t1),0> }
            #local t2=t2+1;
        #end 
    }              
    #local num = num + 1;
    #end
  }
#end

#declare drop = 
  merge {
    sphere {0,1.5 scale<1,.65,1>}
    cone {y*.4,1.37,y*3.1,0}
    translate y*-.6375
    scale<.425,.5259,.425>
    rotate<0,0,60>
    texture { NBglass }
    finish { diffuse 1 }
  }

#macro WaterF(itlevel)
  union { 
    #local num=1;
    #local s=.9;
    #local s2=.4;
    #while (num < itlevel)
      union {  
        #local t1=5;
        #local t2=0;
        #while (t2 < t1)
          object {drop translate<3,(num-1)*s2,0> scale <1/num*s,1,1/num*s> rotate<0,360-(t2*360/t1),0> }
          #local t2=t2+1;
        #end
      }              
      #local num = num + 1;
    #end
  }
#end

#macro sierpinski(s, base_center, recursion_depth)
    #if (recursion_depth > 0)
        union {       
            sierpinski(s / 2, base_center + s/2*y,      recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(x+z),  recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(x-z),  recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(-x+z), recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(-x-z), recursion_depth - 1)
        }
    #else
        difference{
            box { <1,1,1>, <-1,0,-1> }
            plane { x-y,  -sqrt(2)/2 }
            plane { -x-y, -sqrt(2)/2 }
            plane { z-y,  -sqrt(2)/2 }
            plane { -z-y, -sqrt(2)/2 }
            scale s*1.0
            translate base_center
        }
    #end
#end

#macro Bird (F)
#declare Flap = sin(F*2*pi);
#declare Tipflap = sin(F*2*pi-pi/2);
    union {
        union {  // right wing
            object { 
                Wingtip
                rotate <-15+35*Tipflap,-24,0>
                translate -z*1.25
            }
            object { Wing }
            rotate <60*Flap,-7,10>
            translate <0.5,0.438,-0.625>
        } 
        union {  // left wing
            object { 
                Wingtip
                rotate <15-35*Tipflap,-24,0>
                translate -z*1.25
            }
            object { Wing }
            rotate <180-60*Flap,7,10>
            translate <0.5,0.438,0.625>
        }
        sphere { 
            0,1 // right eye
            scale <0.094,0.094,0.04>
            rotate x*10
            translate <1.875,0.812,-0.344>
            texture {
                pigment { color rgb 0.1}
                finish { phong 1 phong_size 100 }
            }
        }
        sphere { 0,1 // left eye
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
                texture { pigment { color rgb <1,0.8,0> } }
            }
        }    // end blob
        texture {
            pigment {
                bozo  color_map {
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
object { 
    Dodecahedron bounded_by {box { <-1.5,-1.5,-1.5>,<1.5,1.5,1.5> } }
    scale <1,1,1>*0.75  
    rotate<25,25,0>
};

#macro Linie (P1,P2,dick)
    sphere_sweep {
        linear_spline
        2,
        P1, dick
        P2, dick
        tolerance 0.001
    }
#end

#macro TetraederBaum(itlevel, Atom,sf)
    union {
        object {
            Atom
            scale sf
        } 
        #if (itlevel>0)
            #local num=0; 
            #while (num < 4)
                object {
                    union {     
                        Linie (<0,0,0>, 0.5*TetraEcken[num],0.02)
                            object {
                                TetraederBaum(itlevel-1,Atom,sf)
                                scale sf
                                translate 0.5*(TetraEcken[num])
                            }
                        }  
                    }
                #local num = num +1;
            #end
        #end
    }   
#end

#declare corteza =
    texture {
        pigment {
            crackle 
            turbulence 0.4 lambda 3.2 
            color_map {
                [0 color rgb <1,0.6,0.31>*.3]
                [0.1 color rgb <1,0.6,0.31>*.4]
                [0.6 color rgb <1,0.6,0.31>*.8]
                [1 color rgb <1,0.6,0.31>*1.2]
            }
        }
        finish { ambient 0.1 }
        scale <0.2,0.7,0.2>*1
    }

#macro WooblyTree(woodBaseX,woodBaseY,woodBaseZ,woodEnd,rad,it)
union{
    object {
        TetraederBaum(it,sphere { <0, 0, 0>,0.5 },<0.5, 0.5, 0.5>)
        pigment { DarkGreen }
        rotate y*-30
        translate <woodBaseX,woodEnd,woodBaseZ>
    }
    cylinder {
        <woodBaseX,woodBaseY,woodBaseZ>,<woodBaseX,woodEnd,woodBaseZ>,rad
        texture { corteza scale .03 }
    }
}
#end


//-------------------- Escena --------------------------------------------------------
union {
    object {
        Fountain(20)
        scale .1 
        rotate<0,0,0>
    } 
    object {
        WaterF(20) 
        scale .12 
        rotate<180,20,0>
        translate<0,1.2,0>
    } 
    translate<-.15,0,1>
    scale 0.3
}

plane { <0,1,0>,0
    texture { Plaza_Texture }
}

#object {
    WooblyTree(0,0,0,0.7,0.08,3)
    translate<0.2,0,1>
}  

#object {
    WooblyTree(0.55,0,0,0.7,0.08,3)
} 

#object {
    WooblyTree(0.4,0,0.5,0.7,0.08,3)
}

#object {
    WooblyTree(0,0,0,0.7,0.08,3)
    rotate<0,90,0>
    translate<-0.5,0,1>
} 
#object {
    WooblyTree(0,0,0,0.7,0.08,3)
    rotate<0,90,0>
    translate<-0.65,0,0.5>
} 
       
#object {
    WooblyTree(0,0,0,0.7,0.08,3)
    rotate<0,90,0>
    translate<-0.7,0,0>
} 

object {
    sierpinski(6, <0.8, 0, 0>, 5)
    scale <1, 1.3, 1>
    rotate<0,-5,0>
    translate<-1.9,0, 10>
    pigment {
        image_map { png "Assets/Arenisca.png" }
    }
}

 
#object { 
    Bird (clock)
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