#include<bits/stdc++.h>
using namespace std;

int mod = (int)1e9+7;

//Binary exponentioal function
long PowBinaryExp(long a, long b) {
    if(b==0) return 1;

    long temp = pow(a, b/2);

    if(b%2==0) {
        return (temp*temp) % mod;
    }else{
        return (a*temp*temp) % mod;
    }
}

int countGoodNumbers(long long n) {
    long long even = (n+1)/2;
    long long odd = n/2;

    long long a = PowBinaryExp(5,even)%mod;
    long long b = PowBinaryExp(4, odd)%mod;

    return (int) ((a*b)%mod);
}


int main() {
    cout<<countGoodNumbers(4)<<endl;
    return 0;
}