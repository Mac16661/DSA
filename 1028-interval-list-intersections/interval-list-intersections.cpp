class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;

        int i=0, j=0;

        while(i<n && j<m) {
            int s1 = firstList[i][0], s2 = secondList[j][0];
            int e1 = firstList[i][1], e2 = secondList[j][1];
            int st = max(s1, s2);
            int end = min(e1, e2);

            // should intersect 
            if(st <= end) {
                ans.push_back({st, end});
            }

            if(e1 <= e2) i++;
            else j++;
        }
        return ans;
    }
};