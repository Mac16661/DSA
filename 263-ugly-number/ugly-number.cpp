class Solution {
public:
    bool isUgly(int n) {
        // if(n > -2 && n < 2) return true; // handeling -ve cases
        if(n <= 0) return false;
        if(n == 1) return true;

        while(n%2==0 || n%3==0 || n%5==0) {
            if(n%2==0) {
                n /= 2;
            }else if(n%3==0) {
                n /=3;
            }else if(n%5==0) {
                n /=5;
            }
        }

        if(n==1 or n==-1) return true;
        return false;
    }
};