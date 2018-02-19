#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[], char* envp[])
{
 unsigned int num = atoi(argv[argc-1]);
 for(unsigned int j = 0; j < num;j++){
   printf("Hello");
   for(unsigned int i = 1; i < argc-1; i++){
     printf(" %s", argv[i]);
   }
 printf("!\n");
}
 return 0;
}
