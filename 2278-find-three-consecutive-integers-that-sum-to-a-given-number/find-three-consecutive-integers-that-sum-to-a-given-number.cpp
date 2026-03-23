class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // sliding window
        // int l=1;
        // int r=3;
        // int currSum = 6;
        
        // while(r <= num) {
        //     if(currSum == num) {
        //         return {l, l+1, r};
        //     }

        //     currSum -= l;
        //     l++;
        //     r++;
        //     currSum += r;

        // }

        // return {};

        if(num%3!=0) return {};
        return {(num/3)-1,(num/3),(num/3)+1};
    }
};