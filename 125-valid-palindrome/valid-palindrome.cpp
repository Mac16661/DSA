class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0, j=s.size()-1;

        while(i<j) {
            // skiping all non alfa num char
            while( i < j && !isalnum(s[i])) i++;
            while( j > i && !isalnum(s[j])) j--;
            
            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};