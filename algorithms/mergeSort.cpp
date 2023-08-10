#include <iostream>

void merge(int arr[], int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;

        int left[n1], right[n2];

        for (int i = 0; i < n1; ++i) {
                left[i] = arr[start + i];
        }
        for (int j = 0; j< n2; ++j) {
                right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, index = start;
        while(i < n1 && j < n2) {
                if(left[i] < right[j]) {
                        arr[index++] = left[i++];
                } else {
                        arr[index++] = right[j++];
                }
        }
        while (i < n1) {
                arr[index++] = left[i++];
        }
        while (j < n2) {
                arr[index++] = right[j++];
        }

}

void mergeSort(int arr[], int start, int end) {
        if(start < end) {
                int mid = start + (end - start) / 2;
                mergeSort(arr, start, mid);
                mergeSort(arr, mid + 1, end);
                merge(arr, start, mid, end);
        }
}

int main() {
        int arr[] = {7, 4, 8, 5, 1, 2, 6, 9};
        mergeSort(arr, 0, 7);
        for(int i = 0; i < 8; ++i) {
                std::cout << arr[i];
        }
}
