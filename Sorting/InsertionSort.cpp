#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,3,5,6,2,0};
    int n = 6;

    // It is also efficient when it is already sorted best case O(n)
     for(int i=0; i<n; i++){
        int j=i;

        while(j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        } 
     }

    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}