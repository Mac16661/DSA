#include<bits/stdc++.h>
using namespace std;

// If dont put & it will take arr as call by value
void selectionSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
        }
    }

}

int main() {
    vector<int> arr {13,46,24,52,20,9}; 
    selectionSort(arr);

    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}