class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR Property
        int xor1 = 0;

        for(auto i: nums) {
            xor1 = xor1 ^ i;
        }

        return xor1;
    }
};