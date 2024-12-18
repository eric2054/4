void MinMaxHeap::DeleteMin() {
    if (tail == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    int minValue = arr[1];
    cout << "Deleting : " << minValue << endl;

    arr[1] = arr[tail--];

    int current = 1;
    while (true) {
        int leftChild = current * 2;
        int rightChild = current * 2 + 1;
        int swapIndex = current;

        int currentLevel = log(current) / log(2);
        bool isMinLevel = (currentLevel % 2 == 0);

        if (leftChild <= tail) {
            if (isMinLevel && arr[leftChild] < arr[swapIndex]) {
                swapIndex = leftChild;
            } else if (!isMinLevel && arr[leftChild] > arr[swapIndex]) {
                swapIndex = leftChild;
            }
        }
        if (rightChild <= tail) {
            if (isMinLevel && arr[rightChild] < arr[swapIndex]) {
                swapIndex = rightChild;
            } else if (!isMinLevel && arr[rightChild] > arr[swapIndex]) {
                swapIndex = rightChild;
            }
        }

        if (swapIndex == current) {
            break;
        }

        swap(arr[current], arr[swapIndex]);
        current = swapIndex;
    }
}

