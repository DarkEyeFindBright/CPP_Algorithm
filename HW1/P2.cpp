/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;

void mirror(int v[], int n){
	
	int temp;
	for(int i=0;i<(n+1)/2;i++)
	{
		temp=v[i];
		v[i]=v[n-i-1];
		v[n-i-1]=temp;
	}
}


int main(){
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4};
	
	mirror(a,5);
	mirror(b,4);
	
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=0;i<4;i++)
		cout<<b[i]<<" ";
	cout<<"\n";
	
	return 0;
}