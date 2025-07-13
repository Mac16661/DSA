class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> &last = intervals[0];
        int count = 0;
        
        for(int i=1; i<intervals.size(); i++){
            // cout<<i<<" -> "<<last[1]<< " : "<<intervals[i][0]<<endl;
            // if overlapping 
            if(last[1] > intervals[i][0]){
                count++;
            }else{
                last = intervals[i];
            }

        }


        return count;
    }
};