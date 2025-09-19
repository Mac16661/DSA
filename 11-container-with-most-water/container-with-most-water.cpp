class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxLen = 0;

        while(l < r) {
            int length = min(height[l] , height[r]);
            int width = r-l;
            int area = length*width;
            maxLen = max(maxLen, area);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return maxLen;
    }
};