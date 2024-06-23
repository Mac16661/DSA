#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    // for(int i=0; i<n-1; i++){
    //     for(int j=1; j<n-i; j++){
    //         if(arr[j-1] > arr[j]) swap(arr[j],arr[j-1]);
    //     }
    // }

    // Solution is very efficient O(n) when the arr is sorted
    for(int i=0; i<n-1; i++) {
        int didSwap = 0;
        for(int j=1; j<n-i; j++) {
            if(arr[j-1] > arr[j]) {
                swap(arr[j], arr[j-1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        cout<<"run\n"<<endl;
    }

    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}