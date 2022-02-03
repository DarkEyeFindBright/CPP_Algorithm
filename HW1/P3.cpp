#include<iostream>
#include<string>
using namespace std;

//Data structure for Grade
struct GradeNode {
	string name = " ";
	int grade = 0;
    bool operator<= (GradeNode& right) {
        return this->grade <= right.grade;
    }
};

//QuickSort
void swap(GradeNode* a, GradeNode* b)
{
    GradeNode t = *a;
    *a = *b;
    *b = t;
}

int partition(GradeNode arr[], int low, int high)
{
    GradeNode pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(GradeNode arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}





int main() {
	int num;
	cout << "The number of Students:";
	cin >> num;
	string Name;
	int Grade;
    float total = 0;
	GradeNode* GradeList = new GradeNode[num];
	for (int i = 0; i < num; i++) {
		cout << "Input Name:";
			cin >> Name;
			cout << "Input Grade:";
			cin >> Grade;
			GradeList[i].name = Name;
			GradeList[i].grade = Grade;
	}

    quickSort(GradeList, 0, num-1);

	for (int i = num-1; i > -1; i--) {
		cout << GradeList[i].name << " " << GradeList[i].grade << endl;
        total += GradeList[i].grade;
	}

    cout << "The Max Grade: " << GradeList[num - 1].name << " "<<GradeList[num-1].grade << endl;
    cout << "The Min Grade: " << GradeList[0].name << " " << GradeList[0].grade << endl;
    cout << "The Ave Grade: " << total/num <<endl;
    cout << "The Median Grade: " << GradeList[num/2].grade << endl;
    delete[] GradeList;
}
