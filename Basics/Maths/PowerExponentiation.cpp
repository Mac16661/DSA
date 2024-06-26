#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;

    while(n > 0) {
        if(n%2 == 1) { //if n is odd number
            ans = ans * x;
            n = n -1;
        }else{
            n = n /2;
            x=x*x;
        }
    }

    return ans;

}

// TODO: Implement its recursive version
int myPowRec(double x, int n) {

    if(n == 0) return 1.0;

    if(n%2 == 0) {
        double half = myPowRec(x, n/2);
        return half * half;
    }else {
        return x * myPowRec(x, n-1);
    }
    
}

int main() {
    cout<<myPowRec(2,3)<<endl;
    return 0;
}