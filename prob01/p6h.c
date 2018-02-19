// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_LENGTH 256

int main(int argc, char * argv[], char* envp[]){
  if(argc != 3){
    perror("usage: p6h file1 file2");
    strerror(EIO);
    exit(EIO);
  }
  FILE *src, *dst;
  char buf[BUF_LENGTH];
  if ( ( src = fopen( argv[1], "r") ) == NULL ){
    printf("The program terminated with exit code %d\n",errno);
    exit(1);
  }
  if ( ( dst = fopen( argv[2], "w" ) ) == NULL ){
    printf("The program terminated with exit code %d\n",errno);
    exit(2);
  }
  while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ){
    fputs( buf, dst );
  }
  fclose( src );
  fclose( dst );
  exit(0); // zero é geralmente indicativo de "sucesso"
}
