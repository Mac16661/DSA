class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int j = 0;
        int cnt = 0;
        int len = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                cnt++;
            }

            while (j <= i && cnt > k) {
                if (nums[j]==0) cnt--;
                j++;
            }

            len = max(len, i - j + 1);
        }

        return len;
    }
};