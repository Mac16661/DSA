class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
         vector<pair<int, int>> intervals;

        // Convert tap ranges to intervals [start, end]
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            intervals.push_back({left, right});
        }

        // Sort intervals by start point
        sort(intervals.begin(), intervals.end());

        // for(auto inter: intervals){
        //     cout<<inter.first<<" "<<inter.second<<endl;
        // }

        int end = 0, nextEnd = 0, i = 0, count = 0;

        while (end < n) {
            // Extend coverage as far as possible
            while (i < intervals.size() && intervals[i].first <= end) {
                nextEnd = max(nextEnd, intervals[i].second);
                i++;
            }
            // cout<<end<<" -> "<<nextEnd<<endl;
            if (end == nextEnd) return -1; // Can't progress
            end = nextEnd;
            count++;
        }

        return count;
    }
};