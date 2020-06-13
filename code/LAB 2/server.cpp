/*
** spock.c -- reads from a message queue
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
using namespace std;
struct my_msgbuf {
	long mtype;
	char mtext[200];
	char file[200];
	char mail[200];
	long choice,ncmd;
	char cmd[5][200];
};
int main(void)
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;

	if ((key = ftok("client.cpp", 'B')) == -1) {  /* same key as kirk.c */
		perror("ftok");
		exit(1);
	}

	if ((msqid = msgget(key, 0644)) == -1) { /* connect to the queue */
		perror("msgget");
		exit(1);
	}
	sleep(30);
	printf("Ready to receive messages.\n");
	for(;;)
	{
		if (msgrcv(msqid, &buf,sizeof(buf),-4, 0) == -1) {
        	perror("msgrcv");
          exit(1);
    }
		if(buf.mtype == 1)
		{
			if(buf.choice == 1)
			{
				string str = "gcc";
				str = str + " -o a.out "+ buf.file;
				const char *command = str.c_str();
				system(command);
				system("./a.out");
				cout<<"File executed."<<endl;
			}
			else if(buf.choice == 2)
			{
				string str = buf.cmd[0];
				if(buf.ncmd>1)
					str = str + " | ";
				for(int i=1;i<buf.ncmd;i++)
				{
					if(i == buf.ncmd - 1)
						str = str + buf.cmd[i];
					else
						str = str + buf.cmd[i] + " | ";
				}
				const char *command = str.c_str();
				system(command);
			}
		}
		else if(buf.mtype == 2)
		{
			cout<<"Sending mail..."<<endl;
			string str="echo";
			str = str + " \"PFA\" | mutt -s \"Attachment\"" + " " +buf.mail +" -a"+ " " +buf.file;
			const char *command = str.c_str();
			system(command);
			cout<<"Mail sent."<<endl;
		}

		else if(buf.mtype == 3)
		{
			string str = "vlc";
			str = str + " "+ buf.mtext;
			const char *command = str.c_str();
			system(command);
			cout<<"video closed."<<endl;
		}
		else if(buf.mtype == 4)
		{
			cout<<"Opening "<<buf.file<<"..."<<endl;
			string str = "atom";
			str = str + " "+ buf.file;
			const char *command = str.c_str();
			system(command);
			cout<<"done"<<endl;
		}

	}

	return 0;
}
