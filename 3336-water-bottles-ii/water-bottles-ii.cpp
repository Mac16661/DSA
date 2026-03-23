class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;

        while(numBottles >= numExchange) {
            // buying new bottle 
            numBottles -= numExchange;
            drank++;
            numBottles++;
            numExchange++;
        }

        return drank;
    }
};