#version 3.5;
global_settings {assumed_gamma 1.0}
background {rgb <1,0.9,0.9>}
camera {location <1.6,5,-6> look_at <1.5,0,1.5> angle 40}
light_source {<500,500,-500> rgb 1 }

#declare B11=<0,0,3>; #declare B12=<1,0,3>; //
#declare B13=<2,0,3>; #declare B14=<3,0,3>; // row 1

#declare B21=<0,0,2>; #declare B22=<1,0,2>; //
#declare B23=<2,0,2>; #declare B24=<3,0,2>; // row 2

#declare B31=<0,0,1>; #declare B32=<1,0,1>; //
#declare B33=<2,0,1>; #declare B34=<3,0,1>; // row 3

#declare B41=<0,0,0>; #declare B42=<1,0,0>; //
#declare B43=<2,0,0>; #declare B44=<3,0,0>; // row 4

bicubic_patch {
   type 1 flatness 0.001
   u_steps 4 v_steps 4
   uv_vectors
   <0,0> <1,0> <1,1> <0,1>
   B11, B12, B13, B14
   B21, B22, B23, B24
   B31, B32, B33, B34
   B41, B42, B43, B44
   uv_mapping
   texture {
      pigment {
         checker 
         color rgbf <1,1,1,0.5> 
         color rgbf <0,0,1,0.7> 
         scale 1/3
      }
      finish {phong 0.6 phong_size 20}
   }
   no_shadow
}

#declare Points=array[16]{
   B11, B12, B13, B14
   B21, B22, B23, B24
   B31, B32, B33, B34
   B41, B42, B43, B44
}
#declare I=0;
#while (I<16)
   sphere {
      Points[I],0.1 
      no_shadow 
      pigment{
         #if (I=0|I=3|I=12|I=15)
            color rgb <1,0,0>
         #else
            color rgb <0,1,1>
         #end
      }
   }
   #declare I=I+1;
#end