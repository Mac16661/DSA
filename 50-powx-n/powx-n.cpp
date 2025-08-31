// class Solution {
// public:
    // double myPow(double x, int n) {
    //     if(n == 0) return 1;

    //     if(n<0) {
    //         return 1 / myPow(x, -n); //TODO: very clever
    //     }
         
    //     return x * myPow(x, n-1);
    // }

    // double myPow(double x, int n) {
    //     long exp=n;
    //     double result=1;
        
    //     if (exp < 0) {
    //         x = 1 / x;         // reciprocal
    //         exp = -exp;        // make exponent positive
    //     }

    //     for(int i=1; i<=exp; i++) {
    //         result *= x;
    //     }
    //     return result;
    // }
class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;       // use long to handle INT_MIN case
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {   
                result *= x;
            }
            x *= x;               
            exp /= 2;
        }

        return result;
    }
};

