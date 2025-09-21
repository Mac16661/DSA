class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0;
        int maxLen=0;
        int zeroCnt=0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zeroCnt++;

            while(zeroCnt > k) {
                if(nums[j] == 0) zeroCnt--;
                j++;
            }

            maxLen = max(maxLen, i-j+1);
        }

        return maxLen;
    }
};