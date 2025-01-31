#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) {
        int j = i;

        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }

    }
}

int main() {
    vector<int> arr {13,46,24,52,20,9}; 
    insertionSort(arr);

    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}