#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[], char* envp[])
{
  for(unsigned int i = 0; envp[i] != NULL; i++){
    if(strncmp("USER=",envp[i],5) == 0){
      char* nome = envp[i]+5;
      printf("Hello %s!\n",nome);
    }
   }
 return 0;
}
