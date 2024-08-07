class Solution {
public:
    int countSum(vector<int>& nums, int k, int m) {
        int sum=0; int splits = 1;

        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i] > m){
                sum = nums[i];
                splits++;
            }else{
                sum+= nums[i];
            }
        }
        return splits;

    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        if(nums.size() < k) return -1;
        if(nums.size() == k) return low;

        while(low<=high){
            int mid = (low+high)/2;

            int splits = countSum(nums,k,mid);

            if(splits > k){
                low = mid + 1;
            }else {
                high = mid - 1;
            }

        }
        return low;
    }
};