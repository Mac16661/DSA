class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSums;
        prevSums[0] = 1; // Base case: a sum of 0 has been seen once
        
        int count = 0;
        int currentSum = 0;
        
        for (int x : nums) {
            currentSum += x;
           
            if (prevSums.find(currentSum - k) != prevSums.end()) {
                count += prevSums[currentSum - k];
            }
            
            prevSums[currentSum]++;
        }
        
        return count;
    }
};