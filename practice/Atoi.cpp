#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // Recursively finds the ans
    long helper(string s,int sign, long ans, int i){
        if(s[i] == ' ' || !isdigit(s[i])) return ans;

        ans = ans * 10 + s[i] - '0';
        

        if(sign == 1 && ans > INT_MAX) return INT_MAX;
        if(sign == -1 && -1*ans < INT_MIN) return INT_MIN;

        return helper(s, sign, ans, i+1);
    }

    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;

        //skip the white space
        while(s[i] == ' ' && i < s.size()) {
            i++;
        }
        s = s.substr(i); 
        
        // set the sign
        int sign = +1;
        long ans = 0;
        if(s[0] == '-') sign = -1;

        // setting the index 
        int MIN = INT_MIN, MAX = INT_MAX;
        i = (s[0] == '+' || s[0] == '-') ? 1: 0;

        
        // while(i < s.length()) {
        //     if(s[i] == ' ' || !isdigit(s[i])) break;    

        //     ans = ans*10 + s[i] - '0'; // convert char to int

        //     if(sign == 1 && ans > MAX) return MAX;
        //     if(sign == -1 && -1*ans < MIN) return MIN;
        //     i++;
        // }

        ans = helper(s, sign, ans, i);

        return (int)(ans*sign);

    }
};

int main() {
    Solution s;
    cout<<s.myAtoi("-143")<<endl;
    return 0;
}