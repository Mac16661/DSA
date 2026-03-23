class Solution {
public:
    bool check(string s, int i, int j) {
        while(i<=j){ 
            if(s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 0;
        string ans;

        // we are basically expandig in both direction from the ith pos and checking if s[l] == s[r]
        for(int i=0; i<n; i++) {
            int l=i,r=i;

            // for odd one
            while(l >= 0 && r<n && s[l] == s[r]){
                if(r-l+1 > maxL) {
                    maxL = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }

            l=i,r=i+1;

            // for even one
            while(l >= 0 && r<n && s[l] == s[r]){
                if(r-l+1 > maxL) {
                    maxL = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};