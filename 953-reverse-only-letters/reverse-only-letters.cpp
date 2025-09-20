class Solution {
public:
    bool isLetter(char c) {
        if((c>= 'a' && c<='z') or (c>='A' && c<='Z')) return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i=0,j=n-1;

        while(i<j) {
            while(i<j && !isLetter(s[i])) i++;
            while(j>i && !isLetter(s[j])) j--;

            if(i<j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};