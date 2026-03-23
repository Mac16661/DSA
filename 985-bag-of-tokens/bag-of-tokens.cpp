class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i=0, j=n-1;

        int score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());

        while(i<=j) {
            if(tokens[i] <= power) {
                power-=tokens[i];
                i++;
                score++;
            }else if(tokens[j] > power && score > 0) {
                power +=tokens[j];
                j--;
                score--;
            }else {
                break;
            }
            maxScore = max(maxScore, score);
        }

        return maxScore;

    }
};