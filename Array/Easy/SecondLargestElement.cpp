#include<bits/stdc++.h>
using namespace std;

//Brute force approach -> sort the arr and pick second element

// Better approach
int SecondLargest(vector<int> arr, int n) {
    int max = 0;
    int sec = 0;
    for(auto i:arr){
        if(i > max) {
            max = i;
        }
    }

    for(auto i:arr) {
        if(i>sec && i!=max) sec = i;
    }

    return sec;
}

// Optimal approach
int SecLargsOpt(vector<int> arr) {
    int high = 0;
    int secMax = 0;

    for(auto i: arr) {
        if(i > high) {
            secMax = high;
            high = i;
        }

        if(i > secMax && i != high) secMax = i;
    }

    return secMax;
}

int main() {
    vector<int> arr = {5, 9,2, 3, 10, 6, 8};
    // cout<<SecondLargest(arr, arr.size())<<endl;
    cout<<SecLargsOpt(arr)<<endl;
    return 0;
}