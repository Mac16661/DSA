class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        // n digits that can add upto 0
        if(n%2==0) { // can i just push -1 & +1 ?
            for(int i=1; i<n/2+1; i++) {
                ans.push_back(-i);
                ans.push_back(i);
            }
        }else {
            ans.push_back(0);
            for(int i=1; i<n/2+1; i++) {
                ans.push_back(-i);
                ans.push_back(i);
            }
            
        }

        return ans;
    }
};