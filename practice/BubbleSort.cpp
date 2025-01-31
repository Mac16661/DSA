#include<bits/stdc++.h>
using namespace std;
 
void bubbleSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++) {
        for(int j=0; j<arr.size()-i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    vector<int> arr {13,46,24,52,20,9}; 
    bubbleSort(arr);

    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}