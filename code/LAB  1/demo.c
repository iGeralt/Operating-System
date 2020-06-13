/******************************************************************************
  Name : Maurya Sujeet
  Roll no.: 17BCS016
  Assignment 4
  Code : Quick sort
*******************************************************************************/

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int partition(int a[],int low,int high)
{
  int pivot = a[high];
  int i=(low-1);
  for(int j=low;j<=(high-1);j++)
  {
    if(a[j]<=pivot)
    {
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[high],a[i+1]);
  return (i+1);

}
int rpartition(int a[],int low,int high)
{
  srand(time(NULL));
  int random = low + rand()%(high - low);
  swap(a[random],a[high]);
  return partition(a,low,high);
}
void qs(int a[],int low,int high)
{
  if(low<high)
  {
    int pi = rpartition(a,low,high);
    qs(a,low,pi-1);
    qs(a,pi+1,high);
  }
}

void display(int a[],int n)
{
  cout<<"Sorted :"<<endl;
  for(int i=0;i<n;i++)
      cout<<a[i]<<endl;
}

int main()
{
  clock_t begin = clock();

  int n,a[100];
  cout<<"Enter number of elements : ";
  cin>>n;
  cout<<"Enter elements : "<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  qs(a,0,n-1);
  display(a,n);

  clock_t end = clock();
  double time =((double)(end - begin))/(double)CLOCKS_PER_SEC;
  cout<<"Time :"<<time;

  return 0;
}
