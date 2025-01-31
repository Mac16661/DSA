class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s==goal) return true;

        // char shifting and checking
        for(int i = 0; i < s.length(); i++) {
            char ch = s[0];
            s.erase(0,1);

            s+= ch;

            if(s==goal) return true;
        }

        return false;
    }
};