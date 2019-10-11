//Lawrence Scroggs CS201 10/04/19 hw1


//This will hold alll of my function implementation 


#include "myfunc.h"

int PPMconvert::build_array(){

  my_array = (char **)malloc(sizeof(char*)*320);
  for(int i = 0;i < 320;++i)
    my_array[i] = (char *)malloc(sizeof(char*)*200);

}
int read_file(){



}
