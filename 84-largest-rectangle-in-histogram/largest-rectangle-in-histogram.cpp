class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int maxr = 0;
        // for(int i=0; i<heights.size(); i++){
        //     int area=0;
        //     int j=i-1;
        //     // go to left till smaller element is encountered 
        //     while(j>=0){
        //         if(heights[i] <= heights[j]){
        //             area += heights[i];
        //         }else{
        //             break;
        //         }
        //         j--;
        //     }

        //     j = i+1;
        //     // go to right till smaller element is encounterd
        //     while(j<heights.size()){
        //         if(heights[i] <= heights[j]){
        //             area+= heights[i];
        //         }else{
        //             break;
        //         }
        //         j++;
        //     }

        //     area += heights[i];

        //     maxr = max(maxr, area);
        // }

        // return maxr;


        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};