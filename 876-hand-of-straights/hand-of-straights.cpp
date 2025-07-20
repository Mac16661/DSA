class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;  // must divide exactly

        map<int, int> freq;  // map keeps keys sorted automatically
        for(int card : hand) freq[card]++;

        for(auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if(count > 0) {
                // Try to build a group starting at this card
                for(int i = 0; i < groupSize; ++i) {
                    int currCard = start + i;

                    if(freq[currCard] < count) return false;

                    freq[currCard] -= count;
                }
            }
        }

        return true;
    }
};
