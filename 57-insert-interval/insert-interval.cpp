class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = 0, right = intervals.size();
    
        // Binary search to find insert position
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] < newInterval[0])
                left = mid + 1;
            else
                right = mid;
        }
        
        intervals.insert(intervals.begin() + left, newInterval);

        // Merge overlapping intervals
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
        }
};