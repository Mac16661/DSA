class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<4) return false;

        // // 4^15 last pow of 4 that int 32 can store
        // return 1073741824%n == 0;

        while(n!=1) {
            if(n%4 != 0) return false;
            n/=4;
        }

        return true;
    }
};