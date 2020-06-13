#include<iostream>
#include "header.h"
using namespace std;
int main()
{
  int n,x;
  cout<<"Enter number of elements : ";
  cin>>n;
  cout<<endl;
  int arr[n];
  cout<<"Enter elements :"<<endl;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<"Enter Element you want to find :";
  cin>>x;
  cout<<endl;
  cout<<"Using LinearSearch"<<endl;
  int result ;
  result = search(arr, n, x);
  (result == -1)? cout<<"Element is not present in array": cout<<"Element is present at index " <<result<<endl;

  cout<<"Using binarySearch"<<endl;
  result = binarySearch(arr, 0, n, x);
	(result == -1) ? cout << "Element is not present in array": cout << "Element is present at index in sorted array " << result<<endl;
  hashing();
  return 0;
}
