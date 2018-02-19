#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[], char* envp[])
{
  printf("Environment variables:\n");
   for (unsigned int i = 0; envp[i] != NULL; i++)
   {
       printf("%s\n", envp[i]);
   }
   return 0;
}
