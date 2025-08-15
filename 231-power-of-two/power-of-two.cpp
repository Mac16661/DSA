class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long pow = 1;

        // In each iteration i will multiply 2 with pow
        while(pow <= n) {
            if(pow == n) return true;
            else if(pow > n) break;
            pow *= 2; // adding 1 to the power of 2
        }

        return false;
    }
};