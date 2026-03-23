class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sorting be end point a[0] start ponint a[1] end point
        sort(points.begin(), points.end(), [](const auto &a, const auto &b){
            return a[1] < b[1]; 
        });

        int count = 1; 
        int end = points[0][1]; // end of the zero th index

        for(int i = 1; i<points.size(); i++) {
            if(points[i][0] > end) {
                count++;
                end = points[i][1];
            }
        }

        return count;
    }
};