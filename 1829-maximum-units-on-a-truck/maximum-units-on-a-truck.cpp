class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; 
        });

        int maxUnits = 0;
        int i=0;

        while (truckSize > 0 && i < boxTypes.size()) {
            int boxCount = min(truckSize, boxTypes[i][0]);  // take as many as possible
            maxUnits += boxCount * boxTypes[i][1];
            truckSize -= boxCount;
            i++;
        }

        return maxUnits;
    }
};