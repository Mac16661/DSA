// select the minimun element in the unsorted array and put it in front of the sorted array
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,3,5,-6,6,2,0};
    int n = 6;
    
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}