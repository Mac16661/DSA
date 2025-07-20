class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // for(auto p:pairs) cout<<p[0]<<" "<<p[1]<<endl;

        vector<int> last = pairs[0];
        int cnt = 1;

        for(int i=1; i<pairs.size(); i++) {
            if(last[1] < pairs[i][0]) {
                last = pairs[i];
                cnt++;
            }
        }
        return cnt;
    }
};