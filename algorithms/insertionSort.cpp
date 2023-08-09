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

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
