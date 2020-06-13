#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<time.h>
using namespace std;

int main()
{
	// ftok to generate unique key
	key_t key = ftok("shmfile",65);
	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	// shmat to attach to shared memory
  int *arr = (int*)shmat(shmid,(void*)0,0);
	cout<<"Write Data : ";
  srand(time(0));
  for(int i=0;i<100;i++)
    arr[i] = rand();
	printf("Data written in memory: \n");
  for(int i=0;i<100;i++)
    cout<<"Number "<<i<<":"<<arr[i]<<endl;
	//detach from shared memory
	shmdt(arr);
	return 0;
}
