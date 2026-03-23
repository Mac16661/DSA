const int MOD = 1e9 + 7;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    long long factorial(int n) {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }

    int numPrimeArrangements(int n) {
        int primeCount = 0, nonPrimeCount = 0;

        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) 
                primeCount++;
            else 
                nonPrimeCount++;
        }

        if(nonPrimeCount == 0) return primeCount;
        else if(primeCount == 0) return nonPrimeCount;

        long long factPrime = factorial(primeCount);
        long long factNonPrime = factorial(nonPrimeCount);
        return (factPrime * factNonPrime) % MOD;
    }
};