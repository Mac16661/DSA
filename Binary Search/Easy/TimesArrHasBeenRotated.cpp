#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> arr){
    int low = 0;
    int high = arr.size()-1;
    int ans = -1;
    int min = INT_MAX;

    while(low<=high){

        int mid = (low+high)/2;

        if(arr[low] <= arr[high]){
            if(min > arr[low]){
                min = arr[low];
                ans = low;
            }
            break;
        }

        //If left part is sorted
        if(arr[low] <= arr[mid]){
            if(min > arr[low]){
                min = arr[low];
                ans = low;
            }
            low = mid+1;
        }else{ //If right part is sorted
            if(min > arr[mid]){
                min = arr[mid];
                ans = mid;
            }
        }
    }
    return ans;

}

int main() {
    vector<int> arr = {3,4,5,1,2};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
    return 0;
}