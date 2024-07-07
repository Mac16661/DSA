class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = nums.size();
        int sum = 0;

        for(auto i:nums) {
            sum += i;
        }

        int son = (max*(max+1)) / 2;

        return son - sum;
    }
};