class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cInOdd = 0, cInEven = 0; //total no of chips in both even and odd pos

        for(int i=0; i<position.size(); i++) {
            if(position[i]%2==0) cInEven++;
            else cInOdd++;
        }

        return min(cInOdd, cInEven);
    }
};