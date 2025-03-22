// #define ll long long

class Solution {
public:

    long long power(long long x, long long y) {
      long long res = 1;    

      x = x % p; // Update x if it is more than or equal to p
      if (x == 0) return 0; 

      while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res*x) % p;
        
        // we have did the odd step is it was odd, now do the even step
        y = y>>1; // dividing y by 2, y>>1 is same as y/2
        x = (x*x) % p;
      }
      return res;
    }

    int p = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long count4 = n/2;
        long long count5 = n - count4;

        long long ans = ((power(4LL, count4) % p * power(5LL, count5) %p) % p);

        return ans;
    }
};