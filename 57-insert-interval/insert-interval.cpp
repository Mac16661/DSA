class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end()); //, [](const vector<int>& a, const vector<int>& b) {
        //     return a[1] < b[1];
        // });

        
        // for(auto i:intervals) cout<<i[0]<<" "<<i[1]<<" , ";
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        vector<int> &last = ans[0];

        for(int i=1; i<intervals.size(); i++){
            vector<int> &last = ans.back();

            if(last[1] >= intervals[i][0]){
                last = {last[0], max(last[1], intervals[i][1])};     
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};