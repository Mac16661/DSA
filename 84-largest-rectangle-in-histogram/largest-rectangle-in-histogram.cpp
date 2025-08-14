class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }


    // Brute force:
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int maxL = 0; // max area

    //     // Check every possible starting point
    //     for (int i = 0; i < n; i++) {
    //         int minHeight = heights[i];
    //         for (int j = i; j < n; j++) {
    //             minHeight = min(minHeight, heights[j]);
    //             int width = j - i + 1;
    //             int area = minHeight * width;
    //             maxL = max(maxL, area);
    //         }
    //     }
    //     return maxL;   
    // }
};