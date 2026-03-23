class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int cnt =0, i =0, j =nums.size()-1;

        while(i<j) {
            int sum = nums[i] + nums[j];
            if(sum == k) {
                cnt++;
                j--;i++;
            }else if(sum < k) i++;
            else j--;
        }

        return cnt;
    }
};