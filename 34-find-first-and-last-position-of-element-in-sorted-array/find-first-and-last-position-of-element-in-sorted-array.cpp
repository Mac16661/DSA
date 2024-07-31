class Solution {
public:
    int findLastPos(vector<int> arr, int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;

        while(low <= high){
            int mid = (low+high) / 2;

            if(arr[mid] == target){
                ans = mid;
                low = mid+1;
            }else if(arr[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    int findFirstPos(vector<int> arr, int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(arr[mid]== target){
                ans = mid;
                high = mid-1;
            }else if(arr[mid] > target) {
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(findFirstPos(nums, target));
        v.push_back(findLastPos(nums, target));

        return v;
    }
};