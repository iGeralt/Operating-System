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
    int shmid = shmget(key,1024,0666);
    // shmat to attach to shared memory
    int *arr = (int*) shmat(shmid,(void*)0,0);
    printf("Data read from memory: \n");
    int i;
    for(i=0;i<100;i++)
      cout<<"Number "<<i<<":"<<arr[i]<<endl;
    srand(time(0));
    int count=0;
    while(1)
    {
      int a,flag=0;
      a = rand();
      for(int j=0;j<i;j++)
      {
        if(a == arr[j])
          flag=1;
      }
      if(flag == 1)
        continue;
      i++;
      arr[i] = a;
      count++;
      if(count == 100)
        break;
    }
    for(int j=0;j<200;j++)
      cout<<"Number "<<j<<": "<<arr[j]<<endl;
    cout<<endl;
    //detach from shared memory
    shmdt(arr);
    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}
