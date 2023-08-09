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


int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
