class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n<=1) return arr;
        int i=0, j=n-1;
        
        while(j-i >=k) {
            if(x-arr[i] <= arr[j]-x) j--;
            else i++;
        }

        return vector<int>(begin(arr) + i, begin(arr) + j + 1);
    }
};