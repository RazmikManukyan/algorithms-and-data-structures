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

