class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1; // prefix sum = 0 is even
        long long odd = 0;
        long long prefix = 0;
        long long res = 0;

        for(auto x: arr) {
            prefix += x;

            if(prefix%2==0) {
                res+= odd;
                even++;
            }else{
                res+= even;
                odd++;
            }
            res %= MOD;
        } 

        return res;
    }
};