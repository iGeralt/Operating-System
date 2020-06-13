#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define FIFO_NAME "myfifo"
#define FIFO_NAME2 "myfifo2"
int main()
{
	int fd;
	int fd1;
	char output[100];
	while (1)
	{
    memset(output,0,100);
    mknod(FIFO_NAME,S_IFIFO | 0666, 0);
		fd1 = open(FIFO_NAME,O_RDONLY);
		read(fd1,output,100);
		printf("Message from writer using fifo1: %s\n",output);
		for(int i = 0;i<strlen(output)-1;i++)
			++output[i];
		close(fd1);

		mknod(FIFO_NAME2,S_IFIFO | 0666, 0);
		fd = open(FIFO_NAME2,O_WRONLY);
		write(fd,output,strlen(output));
		if((strcmp(output,"exit\n") == 0) || (strcmp(output,"EXIT\n") == 0))
		{
			close(fd);
			break;
		}
		close(fd);
	}
	return 0;
}
