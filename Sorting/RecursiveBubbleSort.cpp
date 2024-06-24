// Recursive selection sort
#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    for (int j = 0; j <= n - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j] , arr[j + 1]);
        }
    }

    //Range reduced after recursion:
    bubble_sort(arr, n - 1);
}

int main() {
    int arr[] = {13,20,24,0,46,52,9};
    bubble_sort(arr,  7);

    for(int i=0; i<=6; i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}