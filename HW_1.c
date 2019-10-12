//Lawrence Scroggs 10/04/19 CS201 Homework 1


//This program converts a PPM file's pixels into an ASCII symbol rendition


#include "hw1given.h"
//#include "IMG_7331_asc.ppm"

int main(int argc, char * argv[]){

  printf("hello again ");
  char * hold;
  
  char buffer[250];
  FILE * fptr = fopen("IMG_7331_asc.ppm","rb");

  int x,y;

  x = 0;
  y = x;

  if(!fptr)
    exit(1);


  fgets(buffer,sizeof(buffer),fptr);

  x = strtol(buffer,&hold,10);
  y = strtol(hold,NULL,10);

  printf("X: %d\n",x);
  printf("Y: %d\n",y);
  printf("File Type: %c%c\n",buffer[0],buffer[1]);
  
  for(int i = 0;i < sizeof(buffer); ++i){
    printf("%d\n",i);
    if(buffer[i] != '#')
        printf("Char: %c\n",buffer[i]);
  }




  return 0;

}
