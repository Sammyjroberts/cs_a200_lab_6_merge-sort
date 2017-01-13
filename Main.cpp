/*
	Roberts, Sammy
    CS A200
 
    October 21 2016
 
    Lab 6
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randomArray(int a[], int numOfElements);
void print(int a[], const int& numOfElements);
void testArray(int a[], int numOfElements);

void mergeSort(int data[ ], int n);
void merge(int data[ ], int n1, int n2);

const int CAPACITY = 20;		

int main()
{
	int a1[CAPACITY];		// sorted in ascending order
	int a2[CAPACITY];		// sorted in descending order
	int a3[CAPACITY];		// random
	int numOfElem = CAPACITY;

	for (int i = 0; i < numOfElem; ++i)
	{
		a1[i] = i + 1;
		a2[i] = numOfElem - i;
	}
	randomArray(a3,numOfElem);  
	
	testArray(a1, numOfElem);
	cout << "\n-------------------------------------------------------------------\n\n";
	testArray(a2, numOfElem);
	cout << "\n-------------------------------------------------------------------\n\n";
	testArray(a3, numOfElem);
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}

void randomArray(int a[], int numOfElements)
{
	srand(static_cast<unsigned int>(time(0)));  
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);
}

void print(int a[], const int& numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}

void testArray(int a[], int numOfElements)
{
	cout << "Array is:\n";
	print(a, numOfElements);
	mergeSort(a, numOfElements);
	cout << "\n\nArray sorted:\n";
	print(a, numOfElements);
}

void mergeSort(int data[ ], int n)
{
    int n1; // Size of the first subarray
    int n2; // Size of the second subarray

    if (n > 1)
    {
        // Compute sizes of the subarrays.
        n1 = n / 2;
        n2 = n - n1;

        mergeSort(data, n1);         // Sort from data[0] through data[n1-1]
        mergeSort((data + n1), n2);  // Sort from data[n1] to the end

        // Merge the two sorted halves.
        merge(data, n1, n2);
    }
}

void merge(int data[ ], int n1, int n2)
{
    int temp[CAPACITY];
    int left = 0;
    int right = n1;
    int end = n1+n2;
    int i = left;
    int j = right;
    
    for(int k = left; k< end; k++) {
        if (i < right && (j >= end || data[i] < data[j])) {
            temp[k] = data[i];
            i++;
        } else {
            temp[k] = data[j];
            j++;
        }
    }
    copy(temp, temp+end, data);
}

