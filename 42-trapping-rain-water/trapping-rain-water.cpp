class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            // Logic: The water level at any point is limited by the shorter side.
            if (height[left] < height[right]) {
                // If current height is >= leftMax, we can't trap water, just update max.
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    // Otherwise, we trap the difference.
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};