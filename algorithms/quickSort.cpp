#include <iostream>

/*int partition(int arr[], int first, int last) {
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
}*/

int partition(int arr[], int first, int last) {
	int key = arr[last];
	int i = first - 1;
	for(int j = first; j <= last - 1; ++j) {
		if(arr[j] <= key) {
		++i;
		std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[last]);
	return i + 1;
}

void quickSort(int arr[], int first, int last) {
	if(first < last) {
		int pivot_index = partition(arr, first, last);
		quickSort(arr, first, pivot_index - 1);
		quickSort(arr, pivot_index + 1, last);
	}
}

	
