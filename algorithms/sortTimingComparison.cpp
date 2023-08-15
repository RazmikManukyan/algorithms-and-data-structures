#include <iostream>
#include <chrono>
#include <vector>

void insertionSort (int arr[], int size)
{
  for (int i = 1; i < size; ++i)
    {
      int j = i - 1;
      int key = arr[i];
      while (j >= 0 && key < arr[j])
	{
	  arr[j + 1] = arr[j];
	  --j;
	}
      arr[j + 1] = key;
    }
  return;
}

void merge (int arr[], int start, int mid, int end)
{
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int left[n1], right[n2];

  for (int i = 0; i < n1; ++i)
    {
      left[i] = arr[start + i];
    }
  for (int j = 0; j < n2; ++j)
    {
      right[j] = arr[mid + 1 + j];
    }

  int i = 0, j = 0, index = start;
  while (i < n1 && j < n2)
    {
      if (left[i] < right[j])
	{
	  arr[index++] = left[i++];
	}
      else
	{
	  arr[index++] = right[j++];
	}
    }
  while (i < n1)
    {
      arr[index++] = left[i++];
    }
  while (j < n2)
    {
      arr[index++] = right[j++];
    }
}

void mergeSort (int arr[], int start, int end)
{
  if (start < end)
    {
      int mid = start + (end - start) / 2;
      mergeSort (arr, start, mid);
      mergeSort (arr, mid + 1, end);
      merge (arr, start, mid, end);
    }
}


int main (){
  int arr[] =
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    1, 2, 3, 4};

  	int n = sizeof (arr) / sizeof (arr[0]);

  	auto start_time = std::chrono::high_resolution_clock::now ();
  	insertionSort (arr, n);
  	auto end_time = std::chrono::high_resolution_clock::now ();
  	auto duration = std::chrono::duration_cast < std::chrono::microseconds >(end_time - start_time);
  	std::cout << "Time taken by insertion sort: " << duration.count () << " microseconds" << std::endl;

  	start_time = std::chrono::high_resolution_clock::now ();
  	mergeSort (arr, 0, n - 1);
  	end_time = std::chrono::high_resolution_clock::now ();
  	duration = std::chrono::duration_cast < std::chrono::microseconds > (end_time - start_time);

 	std::cout << "Time taken by merge sort: " << duration.count () << " microseconds" << std::endl;
}

