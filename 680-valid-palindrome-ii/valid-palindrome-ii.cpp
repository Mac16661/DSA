class Solution {
public:
    bool validPalindromeCheck(string s, int p) {
        int n = s.size();
        int i =0, j=n-1;
        int threshold = 1;

        while(i<j) {
            if(s[i] != s[j]) {
                if(threshold > 0) {
                    threshold--;
                    if(p==0) j--; // we can change either of them i guess (i++)
                    else if(p==1) i++;
                    continue;
                }
                return false;
            }
            i++;j--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        return validPalindromeCheck(s, 0) or validPalindromeCheck(s, 1);
    }
};