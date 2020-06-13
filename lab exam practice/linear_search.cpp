#include <iostream>
#include <pthread.h>
using namespace std;
#define thread_max 4
int a[100],n;
int key;
int flag= 0;
int current_thread = 0;
void* ThreadSearch(void* args)
{
	int num = current_thread++;
	for (int i = num * (n/4);i < ((num + 1) * (n/4)); i++)
	{
		if (a[i] == key)
			flag= 1;
	}
}
int main()
{
	pthread_t thread[thread_max];
  cout<<"Enter size of array : ";
  cin>>n;
  cout<<endl;
  cout<<"Enter array elements : "<<endl;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"Enter element to find : ";
  cin>>key;
  cout<<endl;
	for (int i = 0; i < thread_max; i++)
		pthread_create(&thread[i], NULL,ThreadSearch, (void*)NULL);

	for (int i = 0; i < thread_max; i++)
		pthread_join(thread[i], NULL);

	if (flag == 1)
		cout << "Key element found" << endl;
	else
		cout << "Key not present" << endl;
	return 0;
}
