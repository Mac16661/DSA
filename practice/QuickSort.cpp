#include<bits/stdc++.h>
using namespace std;

int pidx(vector<int> &arr, int low, int high){
    int pivot = arr[low];

    int i = low; 
    int j = high;

    while(i<j) {
        // Find an element greater than the poivot from the left
        while (arr[i] <= pivot && i < high) i++;

        // Find an element smaller than the pivot from the right
        while (arr[j] > pivot && j > low) j--;

        // Swap elements if i < j
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[low]);
    return j;
}

void  qs(vector<int> &arr, int low, int high){
    if(low < high) {
        // find partition index using pivot element
        int idx = pidx(arr, low, high);
        qs(arr, low, idx-1); // left half of arr
        qs(arr, idx+1, high); // right half of arr
    }
}

int main() {
    vector<int> arr = {2, 4, 5, 2, 1, 4, 6, -2};

    // TODO: Always use size - 1 and send it 
    qs(arr, 0, arr.size()-1);

    // Print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}