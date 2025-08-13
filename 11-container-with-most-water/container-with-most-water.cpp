class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxStorage = INT_MIN;

        int i=0, j=n-1;
        while(i<j) {
            int h = min(height[i], height[j]);
            int w = j-i;
            int area = h*w;
            maxStorage = max(maxStorage, area);

            // NOTE: VERY IMP STEP
            if(height[i] < height[j]) i++;
            else j--;
        }

        return maxStorage;
    }
};