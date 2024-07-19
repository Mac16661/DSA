#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n,int x) {
    int low = 0, high = n;
    int ans = n;

    while(low <= high) {
        int mid = (low+high) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;
}

int recLowerBound(vector<int> arr, int x, int low, int high) {
    static int ans = arr.size();
    if(low > high) return ans;

    int mid = (low+high) / 2;

    if(arr[mid] >= x) {
        ans=mid;
        return recLowerBound(arr, x, low, mid-1);
    }else{
        return recLowerBound(arr, x, mid+1, high);
    }

    return ans;
}

int recUpperBound(vector<int> arr, int x, int low, int high) {
    static int ans = arr.size();
    if(low > high) return ans;

    int mid = (low+high) / 2;

    if(arr[mid] > x) {
        ans = mid;
        return recUpperBound(arr, x, low, mid-1);
    }else{
        return recUpperBound(arr, x, mid+1, high);
    }

    return ans;
}

int main() {
    vector<int> arr = {1,2,2,3};
    int n = 4, x = 2;
    int ind = lowerBound(arr, n, x);
    ind = recUpperBound(arr, x, 0, n-1);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}