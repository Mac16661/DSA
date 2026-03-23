class Solution {
public:
    int secondHighest(string s) {
        int first = -1;
        int sec = -1;

        for(int i=0; i<s.size(); i++) {
            if(!isdigit(s[i])) continue;

            int cur = s[i] - '0';
            if(first < cur) {
                sec = first;
                first = cur;
            } else if(sec < cur && cur != first) {
                sec = cur;
            }
        }

        return sec;
    }
};