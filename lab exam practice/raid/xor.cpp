#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int main()
{
  ifstream file1,file2;
  ofstream outf;
  string first ,second;
  cout<<"Enter first image location"<<endl;
  cin>>first;
  //cout<<first;
  cout<<"Enter second image location "<<endl;
  cin>>second;
  file1.open(first,ios::in | ios::binary);
  file2.open(second,ios::in | ios::binary);
  outf.open("outf.txt",ios::out | ios::binary);
  char f1,f2,of;
  file1.seekg(0);
  file2.seekg(0);
  while(!file1.eof() && !file2.eof())
  {
    file1.read(&f1,sizeof(f1));
    file2.read(&f2,sizeof(f2));
    of = f1 ^ f2;
    outf.write(&of,sizeof(of));
    //cout<<c++<<endl;
  }
  file1.close();
  file2.close();
  outf.close();

}
