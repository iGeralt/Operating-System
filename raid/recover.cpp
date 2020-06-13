#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
  ifstream file1,file2;
  ofstream outf;
  char f1,f2,of;
  string part;
  cout<<"Enter 1 part of image"<<endl;
  cin>>part;
  file1.open(part,ios::in|ios::binary);
  file2.open("outf.txt",ios::in|ios::binary);
  outf.open("recovered.txt",ios::out | ios::binary);
  file1.seekg(0);
  file2.seekg(0);
  while(!file1.eof()&& !file2.eof())
  {
    file1.read(&f1,sizeof(f1));
    file2.read(&f2,sizeof(f2));
    of = f1 ^ f2;
  //  cout<<of;
    outf.write(&of,sizeof(of));
  }
  file1.close();
  file2.close();
  outf.close();
}
