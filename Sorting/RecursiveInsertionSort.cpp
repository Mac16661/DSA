// Recursive insertion sort algo
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int i, int n) {
    if(i == n) return;

    int j = i;
    while(j > 0 && arr[j-1] > arr[j]) {
        swap(arr[j-1], arr[j]);
        j--;
    }

    InsertionSort(arr, i+1, n);

}

int main() {
    int arr[] = {13,20,24,46,52,9};
    InsertionSort(arr, 0, 5);

    for(int i=0; i<=5; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}