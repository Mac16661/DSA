class Solution {
public:
    // This problem is about total how much u can store
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans=0;
        // skip the first and last idx
        for(int i=1; i<n-1; i++) {

            // int leftMax = INT_MIN;
            // for(int j=i; j>=0; j-- ){
            //     leftMax = max(leftMax, height[j]);
            // }

            // int rightMax = INT_MIN;
            // for(int j=i; j<n; j++) {
            //     rightMax = max(rightMax, height[j]);
            // }

            // int minWater = min(rightMax, leftMax);
            // ans += minWater-height[i];
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
        
    }
};