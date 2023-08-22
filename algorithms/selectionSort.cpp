#include <iostream>

void selectionSort(int arr[], int size) {
	for(int i = 0; i < size; ++i) {
		int minIndex = i;
		for(int j = i + 1; j < size; ++j) {
			if(arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
	return;
}


