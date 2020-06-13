#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define FIFO_NAME "myfifo"
#define FIFO_NAME2 "myfifo2"
int main()
{
	int fd;
	int fd1;
	char input[100],output[100];
	while (1)
	{
    mknod(FIFO_NAME,S_IFIFO | 0666, 0);
		fd = open(FIFO_NAME,O_WRONLY);
		printf("Enter text here : ");
		fgets(input,sizeof(input),stdin);
		printf("\n");
		write(fd,input,strlen(input));
		close(fd);

		memset(output,0,100);
		mknod(FIFO_NAME2,S_IFIFO | 0666, 0);
		fd1 = open(FIFO_NAME2,O_RDONLY);
		read(fd1,output,100);
		printf("Encrypted message using fifo2: %s\n",output);
		if((strcmp(output,"exit\n") == 0) || (strcmp(output,"EXIT\n") == 0))
		{
			close(fd1);
			break;
		}
		close(fd1);
	}
	return 0;
}
