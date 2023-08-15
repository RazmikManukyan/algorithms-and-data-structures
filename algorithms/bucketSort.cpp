#include <iostream>
#include <vector>
#include <algorithm>

void findMinMax(double arr[], int n, double& minVal, double& maxVal) {
	minVal = arr[0];
	maxVal = arr[0];
	for(int i = 1; i < n; ++i) {
		if(arr[i] < minVal) {
			minVal = arr[i];
		}
		if(arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
}

void bucketSort(double arr[], int n) {
	double minVal, maxVal;
	findMinMax(arr, n, minVal, maxVal);

	const int numBucket = 10;
	std::vector<std::vector<double>> bucket(numBucket);

	for(int i = 0; i < n; ++i) {
		int bucketIndex = (int)(arr[i] - minVal) * (numBucket - 1) / (maxVal - minVal);
	bucket[bucketIndex].push_back(arr[i]);
	}
	
	for(int i = 0; i < numBucket; ++i) {
		std::sort(bucket[i].begin(), bucket[i].end());
	}
	
	int index = 0; 
	for(int i = 0; i < numBucket; ++i) {
		for(int j = 0; j < bucket[i].size(); ++j) {
			arr[index++] = bucket[i][j];
		}
	}
}

int main() {
    double arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
