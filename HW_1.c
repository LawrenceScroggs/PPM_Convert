//Lawrence Scroggs 10/04/19 CS201 Homework 1


//This program converts a PPM file's pixels into an ASCII symbol rendition


#include "hw1given.h"

#define MAX_COLOR 255

int e_distance(Pixel hold_pix); 
char rel_loom(Pixel hold_pix);
Pixel average(Pixel ** pix_array,int c,int r);

int main(int argc, char * argv[]){

  printf("hello again \n\n");
  char * file_type = (char*)malloc(sizeof(char*)*2);
  char * hold;
  Pixel ** pix_array;
  
  char buffer[250];
  FILE * fptr = fopen("DSC_0026b_asc.ppm","rb");

  unsigned int x,y,color_val;
  unsigned char a_char;
  enum Ansi_Color a_color;

  if(!fptr){
    printf("FILE ERROR"); 
    exit(1); 
  }

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
      }
    }
  }
  //check values of img
  /*for(int i = 0; i < x; ++i){
    for(int j = 0; i < y;++i){
      printf("R: %d G: %d B: %d\n",pix_array[i][j].Red,pix_array[i][j].Green,pix_array[i][j].Blue);
    }
  }
  */

    printf("\n");
  for(int i = 0;i < y; i+=8){
    for(int j = 0;j < x; j+=4){

      Pixel e_color = average(pix_array,i,j);
      a_char = rel_loom(e_color);
      a_color = e_distance(e_color);
      
      PrintASCIIChar(a_color,a_char);
    }
    printf("\n");

  }

    printf("\n");

     // printf("Eucledian Distance: %d\n",dist_hold);

/*  else if(strncmp(file_type,"P6",2)== 0){
     printf("Binary Array \n");
     for(int i = 0;i < x;++i){
      for(int j = 0;j < y;++j){
        fread(buffer,sizeof(buffer),fptr);
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
// Calculates Euclidean Distance returns color val
int e_distance(Pixel hold_pix){

  int color_hold = 0;  // holds the winning color

  int smallest = 0; 
  int compare = 0;

  // 1 - BrightBlue
  smallest = sqrt((pow((hold_pix.Red),2)) + (pow((hold_pix.Green),2)) + (pow(255-(hold_pix.Blue),2)));
  color_hold = 0;
  // 2 - BrightGreen
  compare = sqrt((pow((hold_pix.Red),2)) + (pow((255-hold_pix.Green),2)) + (pow((hold_pix.Blue),2)));
  /*
  printf("Compare: %d\n",compare);
  printf("Smallest: %d\n",smallest);
  */
  if(compare < smallest){
    smallest = compare;
    color_hold = 1;
  }
  // 3 - BrightCyan
  compare = sqrt((pow(hold_pix.Red,2)) + (pow((255-hold_pix.Green),2)) + (pow((255-hold_pix.Blue),2)));
  if(compare < smallest){
    smallest = compare;
    color_hold = 2;
  }
  // 4 - BrightRed
  compare = sqrt((pow((255-hold_pix.Red),2)) + (pow(hold_pix.Green,2)) + (pow(hold_pix.Blue,2)));
  if(compare < smallest){
    smallest = compare;
    color_hold = 3;
  }
  // 5 - BrightMagenta
  compare = sqrt((pow((255-hold_pix.Red),2)) + (pow(hold_pix.Green,2)) + (pow((255-hold_pix.Blue),2)));
  if(compare < smallest){
    smallest = compare;
    color_hold = 4;
  }
  // 6 - BrightYellow
  compare = sqrt((pow((255-hold_pix.Red),2)) + (pow((255-hold_pix.Green),2)) + (pow((hold_pix.Blue),2)));
  if(compare < smallest){
    smallest = compare;
    color_hold = 5;
  }
  // 7 - BrightWhite
  compare = sqrt((pow((255-hold_pix.Red),2)) + (pow((255-hold_pix.Green),2)) + (pow((255-hold_pix.Blue),2)));
  if(compare < smallest){
    smallest = compare;
    color_hold = 6;
  }


  return color_hold;
}
//  takes a Pixel pointer and computes the Relative Luminance
char rel_loom(Pixel hold_pix){

  int Y;
  char a_char[] = ASCII_MAP_STRING;

  Y = ((0.21*hold_pix.Red)+(0.71*hold_pix.Green)+(0.08*hold_pix.Blue));

  Y = (Y/3);

  return a_char[Y];

}
Pixel average(Pixel ** pix_array,int col,int row){

  int sum_r = 0;
  int sum_b = 0;
  int sum_g = 0;
  
  unsigned int average_r,average_b,average_g;
  Pixel hold_pix;

  for(int i = col;i < col+8;++i){
    for(int j = row;j < row+4;++j){
      sum_r += pix_array[col][row].Red;
      sum_g += pix_array[col][row].Green;
      sum_b += pix_array[col][row].Blue;
    }
  }
  average_r = (sum_r/32);
  hold_pix.Red = average_r;
  average_g = (sum_g/32);
  hold_pix.Green = average_g;
  average_b = (sum_b/32);
  hold_pix.Blue = average_b;


  return hold_pix;
  
}
