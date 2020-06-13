#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
  int fd;
  fd = open("/media/stark/Games/clg/SEM 4/OS/Self-learning/q1/libsearch.a",O_RDWR);
  struct stat sb;
  if(fstat(fd,&sb) == -1)
    perror("Error");
  printf("size of file is %ld bytes",sb.st_size);
}
