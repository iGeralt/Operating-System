#include<iostream>
#include<semaphore.h>
#include<pthread.h>
using namespace std;
#define THINKING 3
#define HUNGRY 2
#define EATING 1
int N;
int state[100],phil[100];
sem_t mutex,s[100];
void test(int num)
{
  if(state[num] == HUNGRY && state[(num + N-1)%N] != EATING && state[(num + 1)%N] != EATING )
  {
    state[num] = EATING;
    cout<<"Philosopher "<<num+ 1<<" takes fork "<<(num + N-1)%N+1<<" and "<<num + 1<<endl;
    cout<<"Philosopher "<<num + 1<<" is eating"<<endl;
    sem_post(&s[num]);
  }
}
void pickup(int num)
{
  sem_wait(&mutex);
  state[num] = HUNGRY;
  cout<<"Philosopher "<<num+1<<" is hungry."<<endl;
  test(num);
  sem_post(&mutex);
  sem_post(&s[num]);
}
void putdown(int num)
{
  sem_wait(&mutex);
  state[num] = THINKING;
  cout<<"Philosopher "<<num+1<<" is putting fork "<<(num + N-1)%N+1<<" and "<<num+1<<endl;
  cout<<"Philosopher "<<num+1<<" is thinking."<<endl;
  test((num + N-1)%N);
  test((num + 1)%N);
  sem_post(&mutex);
}
void* dining(void* num)
{
  while(1)
  {  int* i = ((int*)num);
    pickup(*i);
    putdown(*i);}

}
int main()
{
  sem_init(&mutex,0,1);
  cout<<"Enter number of philosophers : ";
  cin>>N;
  cout<<endl;
  pthread_t philosophers_id[N];
  for(int i=0;i<N;i++)
    sem_init(&s[i],0,0);
    for(int i=0;i<N;i++)
      phil[i]=i;
  for(int i=0;i<N;i++)
  {
    pthread_create(&philosophers_id[i],NULL,dining,&phil[i]);
    cout<<"Philosopher "<<i+1<<" is thinking "<<endl;
  }
  for(int i=0;i<N;i++)
    pthread_join(philosophers_id[i],NULL);
}
