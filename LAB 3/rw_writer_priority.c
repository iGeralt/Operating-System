#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

sem_t mutex,writeblock,p,x,z;
int data = 0,rcount = 0,wcount = 0;

void *reader(void *arg)
{
//  sem_wait(&z);
  sem_wait(&mutex);
  //sem_wait(&x);
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&writeblock);
  //sem_post(&x);
  sem_post(&mutex);
  //sem_post(&z);
  printf("Data read by the reader%d is %d\n",arg,data);
  //sleep(1);
  sem_wait(&mutex);
  //printf("dec\n");
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  sem_wait(&p);
  wcount++;
  if(wcount == 1)
    sem_wait(&mutex);
  sem_post(&p);
  sem_wait(&writeblock);
  data++;
  printf("Data writen by the writer%d is %d\n",arg,data);
  //sleep(1);
  sem_post(&writeblock);
  sem_wait(&p);
  wcount--;
  if(wcount == 0)
    sem_post(&mutex);
  sem_post(&p);

}

int main()
{
  int i,b,j;
  pthread_t rtid[100],wtid[100];
  sem_init(&p,0,1);
  sem_init(&mutex,0,1);
  sem_init(&z,0,1);
  sem_init(&x,0,1);
  sem_init(&writeblock,0,1);
  for(i=0;i<=10;i++)
    pthread_create(&wtid[i],NULL,writer,(void *)i);
  for(j=0;j<=10;j++)
    pthread_create(&rtid[j],NULL,reader,(void *)j);
  /*for(i=0;i<=10;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }*/
  return 0;
}
