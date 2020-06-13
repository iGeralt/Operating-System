#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FILEPATH "/media/stark/Games/clg/SEM 4/OS/Self-learning/q4/file1.txt"

int main()
{
  int i;
  int fd;
  struct stat sb;
  char *map;  /* mmapped array of int's */
  //FILE* fp = fopen(FILEPATH, "r");
  fd = open(FILEPATH, O_RDWR);
  if (fd == -1)
  {
    perror("Error opening file for reading");
    exit(EXIT_FAILURE);
  }
  if(fstat(fd,&sb) == -1)
    perror("Error\n");
  // fd =(FILE *)fd;
  //fseek(fp, 0L, SEEK_END);
  // calculating the size of the file
  //long int res = ftell(fp);
//  printf("Size of the file is %ld bytes \n", res);

  map = (char*) mmap(0,4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if (map == MAP_FAILED)
  {
    close(fd);
    perror("Error mmapping the file");
    exit(EXIT_FAILURE);
  }

  /* Read the file int-by-int from the mmap
   */
  for (i = 0; i <=sb.st_size; ++i)
  {
    printf("%c\n",map[i]);
    if (map[i] >= 'a' && map[i] <= 'z')
    {
       map[i] = map[i] - 32;
    }
  }
  for (i = 0; i <=sb.st_size; ++i)
  {
    printf("%c\n", map[i]);
  }
  char *new_mapping = mremap(map,sb.st_size,sb.st_size*2,MREMAP_MAYMOVE);
  if (new_mapping == MAP_FAILED)
      // handle error
  map = new_mapping;
  if ( msync(map, sb.st_size , MS_SYNC ) < 0 ) {
          perror("msync failed with error:");
          return -1;
      }
  if (munmap(map,sb.st_size) == -1)
    perror("Error un-mmapping the file");
  close(fd);
  return 0;
}
