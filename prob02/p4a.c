#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(void)
{
 int fd2, nw;
 unsigned char buffer[BUFFER_SIZE];

 fd2 = open("names.txt", O_WRONLY | O_CREAT, 0644);
 if (fd2 == -1) {
  perror(argv[1]);
  return 2;
 }

if(argc == 3){
     dup2(fd2,STDOUT_FILENO);
}

 while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0){
  if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) {
   perror(argv[2]);
   close(fd1);
   close(fd2);
   return 4;
  }
}
  close(fd1);
  close(fd2);
  return 0;
}
