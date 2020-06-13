#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int columns = 2,value,rows =3;
vector< vector< int > > myvector( rows ) ;
for( int i =0 ; i < rows ; i++ ) {
for ( int j=0 ; j < columns ; j++ ) {
cin >> value ;
myvector [ i ].push_back ( value ) ;
} }
for( int i =0 ; i < rows ; i++ )
{
  for ( int j=0 ; j < columns ; j++ )
    cout<<myvector[i][j]<<"\t";
cout<<endl;
}
}
