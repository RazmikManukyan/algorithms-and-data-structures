void max_heapify(int i, int size, std::vector<int>& arr) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(largest, size, arr);
    }
}

void build_MaxHeap(std::vector<int>& arr) {
    int size = arr.size();
    for(int i = size/2 - 1; i >= 0; i--) {
        max_heapify(i, size, arr);
    }
}

void heapSort(std::vector<int>& arr) {
    build_MaxHeap(arr);
    for(int i = arr.size() - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        max_heapify(0, i, arr);
    }
}
