class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
         
        string s="";
        int sign = 1;
        if(num<0) sign = -1;

        while(num) {
            s += to_string(abs(num%7));
            num /= 7;
        }

        reverse(s.begin(), s.end());
        if(sign==-1) s = "-"+s;
        return s;
    }
};