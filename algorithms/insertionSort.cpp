#include <iostream>

void insertionSort(int arr[], int size) {
	for(int i = 1; i < size; ++i) {
		int j = i - 1;
		int key = arr[i];
		while(j >=0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
	return;
}
