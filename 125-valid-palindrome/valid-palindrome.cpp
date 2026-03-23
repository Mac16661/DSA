class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;

        while(i<j) {
            // skiping all non alfa num char
            while( i < j && !isalnum(s[i])) i++;
            while( j > i && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;j--;
        } 

        return true;
    }
};