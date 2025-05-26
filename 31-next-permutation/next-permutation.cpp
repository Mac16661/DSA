class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        int n = nums.size();
        int ind = -1;

        // step 1 find break point
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 2: Find greater element ans swap it with nums[ind]
        for(int i=n-1; i>ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        //reverse the right half
        reverse(nums.begin() + ind+1, nums.end());

    }
};