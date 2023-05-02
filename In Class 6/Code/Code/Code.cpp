#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root_index)
{
    // heapify the subtree rooted at the given root_index
    int largest = root_index;  // largest element in the subtree
    int left_child = 2 * root_index + 1;  // left child index
    int right_child = 2 * root_index + 2;  // right child index

    // check if left child is larger than root
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    // check if right child is larger than largest so far
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    // swap root with largest element if necessary
    if (largest != root_index) {
        swap(arr[root_index], arr[largest]);

        // recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build a max-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // swap the root (largest element) with the last element in the heap
        swap(arr[0], arr[i]);

        // heapify the reduced heap
        heapify(arr, i, 0);
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int input_arr[] = { 41, 1, 312, 129, 90, 69 };
    int size = sizeof(input_arr) / sizeof(input_arr[0]);
    cout << "Input array:\n";
    displayArray(input_arr, size);

    heapSort(input_arr, size);

    cout << "Sorted array:\n";
    displayArray(input_arr, size);
}
