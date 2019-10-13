//Lawrence Scroggs 10/04/19 CS201 Homework 1


//This program converts a PPM file's pixels into an ASCII symbol rendition


#include "hw1given.h"

#define MAX_COLOR 255
//#include "IMG_7331_asc.ppm"

int rel_loom(Pixel * hold_pix);
Pixel * average(Pixel ** pix_array,int c,int r);

int main(int argc, char * argv[]){

  printf("hello again \n\n");
  char * file_type = (char*)malloc(sizeof(char*)*2);
  char * hold;
  Pixel ** pix_array;
  
  char buffer[250];
  FILE * fptr = fopen("IMG_7331_asc.ppm","rb");

  unsigned int x,y,color_val,rel_Lumin;

  if(!fptr)
    exit(1);


  fgets(buffer,sizeof(buffer),fptr);  // grabs first line
  file_type[0] = buffer[0];
  file_type[1] = buffer[1];
  printf("File Type: %s\n",file_type);

  fgets(buffer,sizeof(buffer),fptr); // skips # 
  fgets(buffer,sizeof(buffer),fptr); // line 3

  x = strtol(buffer,&hold,10);  // converts char to int for x & y
  y = strtol(hold,NULL,10);

  printf("X: %d\n",x);
  printf("Y: %d\n",y);


  pix_array = (Pixel**)malloc(sizeof(Pixel*)*x);
  for(int i = 0;i < x;++i)
    pix_array[i] = (Pixel*)malloc(sizeof(Pixel)*y);

  fgets(buffer,sizeof(buffer),fptr); // line 4
  color_val = strtol(buffer,NULL,10);  // gets color value
  printf("Color Value: %d\n",color_val);

  if(strncmp(file_type,"P3",2)== 0){
    printf("ASCII Array \n");
    for(int i = 0;i < x;++i){
      for(int j = 0;j < y;++j){
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Red = strtol(buffer,NULL,10);
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Green = strtol(buffer,NULL,10);
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Blue = strtol(buffer,NULL,10);
        pix_array[i][j].avg = ((pix_array[i][j].Red+pix_array[i][j].Blue+pix_array[i][j].Green)/3); 
      }
    }
  }
  rel_Lumin = rel_loom(average(pix_array,0,0));
  printf("Relative Luminance: %d\n",rel_Lumin);

/*  else if(strncmp(file_type,"P6",2)== 0){
     printf("Binary Array \n");
     for(int i = 0;i < x;++i){
      for(int j = 0;j < y;++j){
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Red = buffer[0];
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Green = buffer[0];
        fgets(buffer,sizeof(buffer),fptr);
        pix_array[i][j].Blue = buffer[0];
      }
    }
  }
*/


  return 0;

}
//  takes a Pixel pointer and computes the Relative Luminance
int rel_loom(Pixel * hold_pix){

  unsigned int Y;

  Y = ((0.21*hold_pix->Red)+(0.71*hold_pix->Green)+(0.8*hold_pix->Blue));

  return Y;

}
Pixel * average(Pixel ** pix_array,int r,int c){

  unsigned int sum_r,sum_b,sum_g;
  unsigned int average_r,average_b,average_g;
  Pixel * hold_pix = (Pixel*)malloc(sizeof(Pixel));

  for(int i = r;i < r+4;++i){
    for(int j = j;j < c+8;++j){
      sum_r += pix_array[r][j].Red;
      sum_g += pix_array[r][j].Green;
      sum_b += pix_array[r][j].Blue;
      printf("Sum R: %d\n",sum_r);
      printf("Sum B: %d\n",sum_b);
      printf("Sum G: %d\n",sum_g);
    }
  }
  average_r = (sum_r/32);
  hold_pix->Red = average_r;
  average_g = (sum_g/32);
  hold_pix->Green = average_g;
  average_b = (sum_b/32);
  hold_pix->Blue = average_b;


  return hold_pix;
  
}
