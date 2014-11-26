#include <iostream>
using namespace std;

void Quicksort(int *array, int start, int end);
int Partition(int *array, int start, int end);
//integer implementation of Quicksort
int main()
{
	int input = 0;
	int size = 0;
	cout << "Please enter the size of the array: \n";
	cin >> size;
	int *q_ary = new int[size];
	cout << "Enter array integers: \n";
	for(int i = 0; i < size; i++)
	{
		cin >> q_ary[i];
	}
	cout << "Starting Array: ";
	for(int i = 0; i < size-1; i++)
	{
		cout << q_ary[i] << ", ";
	}
	cout << q_ary[size-1] << endl;
	Quicksort(q_ary, 0, size-1);
	cout << "New Array: ";
	for(int i = 0; i < size-1; i++)
	{
		cout << q_ary[i] << ", ";
	}
	cout << q_ary[size-1] << endl;
	return 0;
}

void Quicksort(int *array, int start, int end)
{
	if(start < end)
	{
		int q = Partition(array, start, end);
		Quicksort(array, start, q-1);
		Quicksort(array, q+1, end);
	}
}

int Partition(int *array, int start, int end)
{
	int pivot = array[end]; //assign pivot to last element in the array.
	int i = start-1;
	for(int j = start; j < end; j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;			
		}
	}
	int temp = array[i+1];
	array[i+1] = array[end];
	array[end] = temp;
	return i+1;			
}
