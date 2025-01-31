#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &arr, int low, int mid, int high) {
    // Temporary array to store merged elements
    vector<int> temp(high - low + 1);  // vector<int> name(size)
    int i = 0;
    int left = low;
    int right = mid + 1;

    // Merge the two subarrays
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    // Add remaining elements from the left subarray
    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    // Add remaining elements from the right subarray
    while (right <= high) {
        temp[i++] = arr[right++];
    }

    // Transfer merged elements back to the original array
    for (int j = 0; j < temp.size(); j++) {
        arr[low + j] = temp[j];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    // Base condition: If the subarray has one or no elements
    if (low >= high) {
        return;
    }

    // Find the mid-point
    int mid = low + (high - low) / 2;

    // Recursively sort the left and right subarrays
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge the two sorted subarrays
    sort(arr, low, mid, high);
}

int main() {
    vector<int> arr = {2, 4, 5, 2, 1, 4, 6};

    // Call mergeSort on the entire array
    mergeSort(arr, 0, arr.size() - 1);

    // Print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
