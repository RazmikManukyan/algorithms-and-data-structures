#include <iostream>
#include <cstdlib>
#include <ctime>

int randomizedPartition(int arr[], int first, int last) {
	int random_index = first + rand() % (last - first + 1);
	std::swap(arr[random_index], arr[first]);
	
	int key = arr[first];
	int i = first + 1;
	int j = last;
	
	while(i <= j) {
		while(key < arr[j]) {
			--j;
		}
		while(key > arr[i]) {
			++i;
		}
		if(i < j) {
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[first], arr[j]);
	return j;
}

void randomizedQuickSort(int arr[], int first, int last) {
	if(first < last) {
		int pivot_index = randomizedPartition(arr, first, last);
		randomizedQuickSort(arr, first, pivot_index - 1);
		randomizedQuickSort(arr, pivot_index + 1, last);
	}
}


