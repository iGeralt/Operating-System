/*
** kirk.c -- writes to a message queue
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
	int msqid,n;
	key_t key;

	if ((key = ftok("client.cpp", 'B')) == -1) {
		perror("ftok");
		exit(1);
	}

	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget");
		exit(1);
	}

	printf("Enter lines of text, ^D to quit:\n");
	cout<<"Enter number of request : ";
	cin>>n;
	cout<<endl;
	for(int i = 0;i < n;i++)
	{
		cout<<"Enter request type :";
		cin>>buf.mtype;
		cout<<endl;
		if(buf.mtype == 1)
		{
				cout<<"1.Run c file.\n2.Run 4 or more command."<<endl;
				cin>>buf.choice;
				if(buf.choice == 1)
				{
					cout<<"Enter file name: ";
					cin.ignore(1000,'\n');
					cin>>buf.file;
					cout<<endl;
					if(msgsnd(msqid,&buf,sizeof(buf),0) == -1)
						perror("msgsnd");
					if(i == n-1)
						return 0;
				}
				else if(buf.choice == 2)
				{
					cout<<"Enter number of command: ";
					cin.ignore(1000,'\n');
					cin>>buf.ncmd;
					cout<<endl;
					cout<<"Enter commands. "<<endl;
					cin.ignore(1000,'\n');
					for(int j=0;j<buf.ncmd;j++)
					{
						string s="";
						getline(cin,s);
						strcpy(buf.cmd[j],s.c_str());
						s.erase();
					}
					if(msgsnd(msqid,&buf,sizeof(buf),0) == -1)
						perror("msgsnd");
					if(i == n-1)
						return 0;
				}
		}
		if(buf.mtype == 2)
		{
			cout<<"Enter email address : ";
			cin.ignore(1000,'\n');
			cin>>buf.mail;
			cout<<endl;
			cout<<"Enter filename : ";
			cin.ignore(1000,'\n');
			cin>>buf.file;
			cout<<endl;
			if (msgsnd(msqid, &buf,sizeof(buf), 0) == -1)
				perror("msgsnd");
			if(i == n-1)
				return 0;
		}
		else if(buf.mtype == 3)
		{
			cout<<"Enter the name of the video : ";
			cin.ignore(1000,'\n');
			cin>>buf.mtext;
			cout<<endl;
			if (msgsnd(msqid, &buf,sizeof(buf), 0) == -1)
				perror("msgsnd");
			if(i == n-1)
				return 0;
		}
		else if(buf.mtype == 4)
		{
			cout<<"Enter the name of the file : ";
			cin.ignore(1000,'\n');
			cin>>buf.file;
			cout<<endl;
			if (msgsnd(msqid, &buf,sizeof(buf), 0) == -1)
				perror("msgsnd");
			if(i == n-1)
				return 0;
		}
	}
	if (msgctl(msqid, IPC_RMID, NULL) == -1) {
			 perror("msgctl");
			 exit(1);
	 }
	return 0;
}
