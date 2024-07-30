class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     return min(nums);
    // }
    vector<int> numberGame(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i=i+2) {
            swap(nums[i-1], nums[i]);
        }
        
        return nums;
    }
};