class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>> combined;

        for(int i=0; i<n; i++) {
            combined.push_back({aliceValues[i], bobValues[i]});
        }

        sort(combined.begin(), combined.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]+a[1] > b[0]+b[1]; // descending order
        });

        // first -> alice
        // second -> bob
        int aScore = 0;
        int bScore = 0;
        for(int i=0; i<n; i++) {
            if(i%2==0) aScore += combined[i][0];
            else bScore += combined[i][1];
        }

        if(aScore > bScore) return 1;
        else if(aScore < bScore) return -1;
        return 0;
    }
};