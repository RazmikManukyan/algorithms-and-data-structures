#include <iostream>

int binarySearch(int arr[], int start, int end, int target) {
	while(start <= end) {
	int mid = start + (end - start) / 2;	
		if(arr[mid] == target) {	
			return mid;
		}

		if(arr[mid] < target) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return -1;
}

int binary_Search(int arr[], int start, int end, int target) {
	if(end >= start) {
		int mid = start + (end - start) / 2;
		if(arr[mid] == target) {
			return mid;
		} 
		if(arr[mid] < target) {
			return binary_Search(arr, mid + 1, end, target);
		} else {
			return binary_Search(arr, start, mid - 1, target);
		}
	}
	return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result1 = binarySearch(arr, 0, n -1, x);
    int result2 = binary_Search(arr, 0, n - 1, x);
    (result1 == -1)
        ? std::cout << "Element is not present in array"
        : std::cout << "Element is present at index " << result1 << std::endl;
    (result2 == -1)
	? std::cout << "Element is not present in array"
	: std::cout << "Element is present at index " << result2;
    return 0;
}
