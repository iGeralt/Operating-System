#include<iostream>
#include "header.h"
using namespace std;
int main()
{
  int n;
  cout<<"Enter number of elements : ";
  cin>>n;
  int a[n],b[n];
  cout<<"Enter elements : "<<endl;
  for(int i=0;i<n;i++)
  {
     cin>>a[i];
     b[i] = a[i];
  }
  cout<<"Using Quick sort:"<<endl;
  qs(a,0,n-1);
  for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
  cout<<endl;
  cout<<"Using mergeSort:"<<endl;
  mergeSort(b,0,n-1);
  for(int i=0;i<n;i++)
    cout<<b[i]<<"\t";
  cout<<endl;
  return 0;
}
