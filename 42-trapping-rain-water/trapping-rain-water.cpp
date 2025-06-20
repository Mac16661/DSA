class Solution {
public:
    // CAN BE SOLVED BY PRFIX/SUFFIX SUM OR MONTONIC STACK
    // int trap(vector<int>& height) {
    //     int n = height.size() - 1;
    //     int ans = 0;

    //     // not counting 0th and nth element
    //     for(int i=1; i<n; i++) {
    //         // for current node we need to calculate maxHeight->leftside & maxHeight->rightside.
    //         int rightMax = 0;
    //         for(int r=i; r<n+1; r++){
    //             rightMax = max(rightMax, height[r]);
    //         }

    //         int leftMax = 0;
    //         for(int l=i; l>=0; l--){
    //             leftMax = max(leftMax, height[l]);
    //         }

    //         int minWater = min(rightMax, leftMax);
    //         ans += minWater-height[i];
    //     }

    //     return ans;
        
    // }

    // TODO: OPTIMAL -> Prefix sum
    int trap(vector<int>& height) {
        int n = height.size();
    if (n == 0) return 0;

    vector<int> leftH(n), rightH(n);
    int ans = 0;

    // Build left max array
    leftH[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftH[i] = max(leftH[i - 1], height[i]);
    }

    // Build right max array
    rightH[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightH[i] = max(rightH[i + 1], height[i]);
    }

    // Calculate trapped water
    for (int i = 0; i < n; i++) {
        ans += min(leftH[i], rightH[i]) - height[i];
    }

    return ans;
    }
};