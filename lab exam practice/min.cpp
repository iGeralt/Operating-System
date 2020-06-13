#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<algorithm>
#include <sys/mman.h>
using namespace std;
int main()
{
  int n;
  int* i1 = static_cast<int*>(mmap(NULL, sizeof *i1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
  int* i2 = static_cast<int*>(mmap(NULL, sizeof *i2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
  int* i3 = static_cast<int*>(mmap(NULL, sizeof *i3, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
  int* i4 = static_cast<int*>(mmap(NULL, sizeof *i4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
  int* check = static_cast<int*>(mmap(NULL, sizeof *check, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
  *check = 0;
  int* i5;
  int new_arr[4];
  int p,c1,c2;
  cout<<"Enter size of the array : ";
  cin>>n;
  int arr[n];
  cout<<endl;
  cout<<"Enter elements of the array : ";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  p = fork();
  if(p == 0)
  {
    c1 = fork();
    c2 = fork();
    if(c1 > 0 && c2 > 0)
    {
      //first part
      int *a;
      a = max_element(arr + 0, arr + n/4);
      *i1 = *a;
      exit(EXIT_SUCCESS);
    }
    else if(c1 > 0 && c2 == 0)
    {
      //second part
      int *b;
      b = max_element(arr + n/4,arr + n/2);
      *i2 = *b;
      //new_arr[1]=*i2;
      //cout<<*i2<<endl;
      exit(EXIT_SUCCESS);
    }
    else if(c1 == 0 && c2 > 0)
    {
      //third part
      int *c;
      c = max_element(arr + n/2,arr + (n/4)*3);
      *i3 = *c;
      exit(EXIT_SUCCESS);
    }
    else if(c1 == 0 && c2 == 0)
    {
      //fourth part
      int *d;
      d = max_element(arr + (n/4)*3,arr + n);
      *i4 = *d;
      *check = 1;
      exit(EXIT_SUCCESS);
    }
  }
  else
  {
    wait(NULL);
    while(1) // fourth child sometimes runs before parent so this loop has been used to eradicate that problem
    {
      if(*check == 1)
      {
        cout<<"Minimum value :";
        new_arr[0] = *i1;
        new_arr[1] = *i2;
        new_arr[2] = *i3;
        new_arr[3] = *i4;
        munmap(i1,sizeof *i1);
        munmap(i2,sizeof *i2);
        munmap(i3,sizeof *i3);
        munmap(i4,sizeof *i4);
        i5 = max_element(new_arr + 0,new_arr + 4);
        cout<<*i5<<endl;
        break;
      }
    }
  }
}
