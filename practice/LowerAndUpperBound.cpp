#include<bits/stdc++.h>
using namespace std;

int lowerBound(const std::vector<int>& arr, int target) {
    int n = arr.size(); 
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(const vector<int>& arr, int traget) {
    int n = arr.size(); 
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low+high)/2;

        if(arr[mid] > traget) {
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;
}



int main() {
    vector<int> arr = {3,5,8,9,15,19};
    int x = 9;
    int ind = upperBound(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}