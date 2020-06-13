#include<iostream>
#include<limits.h>
using namespace std;
int hashing(){
	int size,hFn,i,choice;
  int element,pos,n=0;

	cout<<"Enter size of hash table\n";
	cin>>size;

	int ary[size];

	cout<<"Enter hash function [if mod 10 enter 10]\n";
	cin>>hFn;

	for(i=0;i<size;i++)
        ary[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty

	do{
		cout<<"Enter your choice\n";
		cout<<" 1-> Insert\n 2-> Delete\n 3-> Searching\n 4-> Display\n 0-> Exit\n";
		cin>>choice;

		switch(choice){
			case 1:


    cout<<"Enter key element to insert\n";
    cin>>element;

    pos = element%hFn;

    while(ary[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
      if(ary[pos]== INT_MAX)
              break;
      pos = (pos+1)%hFn;
      n++;
      if(n==size)
      break;      // If table is full we should break, if not check this, loop will go to infinite loop.
    }

    if(n==size)
          cout<<"Hash table was full of elements\nNo Place to insert this element\n\n";
    else
          ary[pos] = element;
				break;
			case 2:
      cout<<"Enter element to delete\n";
      cout<<element;

      pos = element%hFn;

      while(n++ != size){
        if(ary[pos]==INT_MIN){
          cout<<"Element not found in hash table\n";
          break;
        }
        else if(ary[pos]==element){
          ary[pos]=INT_MAX;
          cout<<"Element deleted\n\n";
          break;
        }
        else{
          pos = (pos+1) % hFn;
        }
      }
      if(--n==size)
            cout<<"Element not found in hash table\n";
				break;
			case 3:
    //  int element,pos,n=0;

      cout<<"Enter element you want to search\n";
      cout<<element;

      pos = element%hFn;

      while(n++ != size){
        if(ary[pos]==element){
          cout<<"\nElement found at index \n",pos;
          break;
        }
        else
                if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
                    pos = (pos+1) %hFn;
      }
      if(--n==size) cout<<"Element not found in hash table\n";
				break;
			case 4:
      cout<<"Index\tValue\n";

      for(int i=0;i<size;i++)
            cout<<i<<"\t"<<ary[i]<<"\n";
				break;
			default:
				cout<<"Enter correct choice\n";
				break;
		}
	}while(choice);

	return 0;
}
