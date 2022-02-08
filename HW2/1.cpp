#include<iostream>
#include<random>
using namespace std;


void merge(int arr[], int p, int q, int r) {

	if (arr[q] <= arr[q + 1])
		return;
	cout << "Loop" << "/n";
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1+1];
	int* R = new int[n2+1];
	for (int i = 0; i < n1; i++) {
		L[i] = arr[i+p];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[i + q+1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
}



void mergeSort(int arr[], int p, int r) {
	if (p >= r)
		return;
	mergeSort(arr, p, (p + r) / 2);
	mergeSort(arr, (p + r) / 2 + 1, r);
	merge(arr, p, (p + r) / 2, r);
}


int main() {
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, 100);//uniform distribution between 1 and 100
	int n;
	cout << "Enter the value of n "; // Entering Value of n
	cin >> n;

	int* A=new int[n];

	cout << "Randomly Generated Numbers are : " << '\n'; // Printing Randomly Generated Numbers
	for (int i = 0; i < n; i++) {

		A[i] = dis(gen);
		cout << A[i] << '\t';
	}
	cout << "\n";
	cout << "Sorted Numbers are : " << '\n'; // Printing Sorted Numbers
	mergeSort(A, 0, n-1);
	for (int i = 0; i < 5; i++)
		cout << A[i] << "\t";
	cout << endl;
	return 0;
}


