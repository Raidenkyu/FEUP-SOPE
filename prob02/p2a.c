// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LENGTH 256

//Dar ao programa nome copy no makefile em -o

int main(int argc, char* argv[]){
  if(argc != 3){
    perror("Invalid number of arguments: Usage copy arg1 arg2");
    exit(1);
  }
  FILE *src, *dst;
  char buf[BUF_LENGTH];
  int num;
  if ( ( src = fopen( "infile.txt", "r") ) == NULL ){
    perror("Error reading text file");
    strerror(1);
    exit(1);
  }
  if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ){
    perror("Error writing text file");
    strerror(2);
    exit(2);
  }
  while( (num = fread( buf, sizeof(char),BUF_LENGTH, src ) ) != 0){
    fwrite( buf, sizeof(char),num, dst );
  }
  fclose( src );
  fclose( dst );
  exit(0); // zero é geralmente indicativo de "sucesso"
}
