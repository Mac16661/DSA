class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int Ox = 0, Oy = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; // dist, index

        for(int i=0; i<points.size(); i++) {
           int x = points[i][0];
            int y = points[i][1];
            int distSquared = x * x + y * y; // no need to actually squaring it

            minHeap.push({distSquared, i});
        }

        vector<vector<int>> ans;

        while(k-- && !minHeap.empty()) {
            ans.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }

        return ans;
    }
};