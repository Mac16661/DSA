class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size()-1;

        if(n==0) return -1;
        if(arr[0] > arr[1]) return 0;
        if(arr[n] > arr[n-1]) return n;

        int low =1;
        int high = n-1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]) return mid;
            else if(arr[mid - 1] < arr[mid]) low = mid+1;
            else if(arr[mid - 1] > arr[mid]) high = mid-1;
            else high = mid - 1;
        }
        return -1;
    }
};