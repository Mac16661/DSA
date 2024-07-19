#include<bits/stdc++.h>
using namespace std;

int iterBS(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size()-1;

    while(low <= high) {
        int mid = (low+high) / 2;

        if(arr[mid] > target) {
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int recBS(vector<int> arr, int target, int low, int high) {
    int mid = (low+high) / 2;

    if(arr[mid] == target) return mid;

    if(low >= high) return -1;

    if(arr[mid] > target) {
        return recBS(arr, target, low, mid-1);
    }else if(arr[mid] < target) {
        return recBS(arr, target, mid+1, high);
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    cout<<iterBS(arr, target)<<endl;
    cout<<recBS(arr, target, 0, arr.size()-1)<<endl;

    return 0;
}