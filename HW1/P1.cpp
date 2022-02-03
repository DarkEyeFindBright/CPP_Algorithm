#include <iostream>

using namespace std;

void SwapP(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void SwapR(int &a, int &b){
	int temp;
	temp = b;
	b = a;
	a = temp;
}

int main(){
	int a = 1;
	int b = 2;
	SwapP(&a ,&b);
	std::cout<<a<<" "<<b<<endl;
	SwapR(a ,b);
	std::cout<<a<<" "<<b<<endl;
	return 0;
}
