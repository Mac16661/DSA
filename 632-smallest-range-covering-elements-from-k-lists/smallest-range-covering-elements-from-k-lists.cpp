class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using T = tuple<int, int, int>; // (value, list index, element index)
        priority_queue<T, vector<T>, greater<T>> minHeap;

        int currentMax = INT_MIN;
        // Step 1: Initialize heap with first element of each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.emplace(nums[i][0], i, 0);
            currentMax = max(currentMax, nums[i][0]);
        }

        vector<int> result = {0, INT_MAX};

        // Step 2: Process heap
        while (true) {
            auto [val, listIdx, elemIdx] = minHeap.top();
            minHeap.pop();

            // Update result range if smaller
            if (currentMax - val < result[1] - result[0]) {
                result = {val, currentMax};
            }

            // Move pointer in the same list
            if (elemIdx + 1 == nums[listIdx].size()) break; // list exhausted

            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.emplace(nextVal, listIdx, elemIdx + 1);
            currentMax = max(currentMax, nextVal);
        }

        return result;
    }
};
