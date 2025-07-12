class Solution {
public:
    int strStr(string haystack, string needle) {
        int windowSize = needle.size();

        for(int i=0; i<haystack.size(); i++) {
            if(haystack.substr(i, windowSize) == needle) return i;
        }

        return -1;
    }
};