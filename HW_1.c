//Lawrence Scroggs 10/04/19 CS201 Homework 1


//This program converts a PPM file's pixels into an ASCII symbol rendition


#include "hw1given.h"

#define MAX_COLOR 255
//#include "IMG_7331_asc.ppm"

int main(int argc, char * argv[]){

  printf("hello again \n\n");
  char * file_type = (char*)malloc(sizeof(char*)*2);
  char * hold;
  Pixel ** pix_array;
  
  char buffer[250];
  FILE * fptr = fopen("IMG_7331_asc.ppm","rb");

  int x,y;

  x = 0;
  y = x;

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


  return 0;

}
