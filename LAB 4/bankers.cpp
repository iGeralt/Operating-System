#include<iostream>
#include<vector>
using namespace std;
int P,R;
bool safe(int process[],int available[],  vector <vector<int>> max,  vector <vector<int>>allot)
{
  int need[P][R];
  for(int i=0;i<P;i++)
    for(int j=0;j<R;j++)
      need[i][j]=max[i][j]-allot[i][j];
  int work[R];
  bool finish[P];
  int safeseq[P];
  for(int i=0;i<R;i++)
  {
    work[i] = available[i];
    finish[i] = false;
  }
  int count = 0;
  while(count < P)
  {
    bool found =  false;
    for(int i=0;i<P;i++)
    {
      if(finish[i] == false)
      {
        int j;
        for(j=0;j<R;j++)
          if(need[i][j] > work[j])
            break;
        if(j == R)
        {
          for(int k=0;k<R;k++)
            work[k]+=allot[i][k];
          safeseq[count++] = i;
          finish[i] = true;
          found = true;
        }
      }
    }
    if(found == false )
    {
      cout<<"System is not in safe state."<<endl;
      return false;
    }
  }
  cout<<"System is in safe state.\nSafe sequence is :";
  for(int i=0;i<P;i++)
    cout<<safeseq[i]<<"\t";
  cout<<endl;
  return true;
}
int main()
{
  //cout<<"Enter number of processes."<<endl;
  cin>>P;
  int process[P];
  for(int i=0;i<P;i++)
    process[i]=i;
  //cout<<"Enter number of resource types."<<endl;
  cin>>R;
  int available[R];
  //cout<<"Enter available resources."<<endl;
  for(int i=0;i<R;i++)
    cin>>available[i];
//  int max[P][R];
  vector <vector<int>> max(P);
  //cout<<"Enter max resources that can be allocated."<<endl;
  for(int i=0;i<P;i++)
    for(int j=0;j<R;j++)
    {
      int temp;
      cin>>temp;
      max[i].push_back(temp);
    }
  //cout<<"Enter resources allocated to the processes."<<endl;
//  int allot[P][R];
  vector <vector<int>> allot(P);
  for(int i=0;i<P;i++)
    for(int j=0;j<R;j++)
    {
      int temp;
      cin>>temp;
      allot[i].push_back(temp);
    }
  safe(process,available,max,allot);
  return 0;
}
