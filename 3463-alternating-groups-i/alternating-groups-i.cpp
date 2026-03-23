class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        int n=c.size();
        int cnt = 0;
        // check 1st and last element
        if(c[0] != c[n-1] && c[0] != c[1]) cnt++;   //for first element
        if(c[0] != c[n-1] && c[n-1] != c[n-2]) cnt++; // for last element

        for(int i=1; i<n-1; i++) {
            if(c[i] != c[i-1] && c[i] != c[i+1]) cnt++;
        }

        return cnt;
    }
};