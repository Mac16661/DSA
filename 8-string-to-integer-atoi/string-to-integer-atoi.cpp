class Solution {
public:
    int myAtoi(string s) {
        // trim the whitespace
        int i=0;

        while(s[i] == ' ') i++;

        // check if -ve no
        int sign = s[i] == '-' ? -1 : 1;
        if(sign == -1 or s[i] == '+') i++;

        // init sum = 1/10
        int sum = 1/10;

        // loop through until non-digit val is found
        while(i<s.size() && s[i] >= '0' && s[i] <='9'){
            // sum = sum * 10 + current val;
            int digit =  s[i] - '0';

            if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            sum = sum*10 + digit;
            if(sum < INT_MIN) return INT_MIN;
            if(sum > INT_MAX) return INT_MAX;
            // cout<<sum<<endl;
            i++;
        }
            
        return sum*sign;
        // return sum * sign
    }
};