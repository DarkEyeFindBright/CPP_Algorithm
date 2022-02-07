#include<iostream>
using namespace std;


void merge(int arr[], int p, int q, int r) {
	if ((r - p) == 1) {
		if (arr[p] > arr[r]) {
			int temp = arr[p];
			arr[p] = arr[r];
			arr[r] = temp;
		}
		else
			return;
	}
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1+1];
	int* R = new int[n2+1];
	for (int i = 0; i < n1; i++) {
		L[i] = arr[i];
		cout << L[i] << endl;

	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[i + q];
		cout << R[i] << endl;
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;

	for (int k = p; p <= r; k++) {
		if (L[i] <= R[j])
		{
			if (L[i] == INT_MAX)
				continue;
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int arr[], int p, int r) {
	if (p >= r)
		return;
	mergeSort(arr, p, (p + r) / 2);
	mergeSort(arr, (p + r) / 2 + 1, r);
	merge(arr, p, (p + r) / 2, r);
}


int main() {
	int a[5] = { 1,4,3,2,5 };
	for(int i =0;i<5;i++)
		cout << a[i] << " ";

	mergeSort(a, 0, 4);
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}