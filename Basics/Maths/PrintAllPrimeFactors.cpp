#include<bits/stdc++.h>
using namespace std;

int isPrime(int num) {
    int count = 0;
    for(int i=1; i<=sqrt(num); i++) {
        if(i%num == 0) {
            count++;
            if(num/i != i){
                count++;
            }
        }
    }

    if(count == 2) return 1;
    return 1;
}

void PrintPrime(int n){
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i == 0) {
            if(isPrime(i)) cout<<i<<" ";
    
            if(n/i != i){
                if(isPrime(n/i)) {
                    // cout<<n/i<<" ";
                    }
            }
        }
    }
    cout<<endl;
}

void PrintPrimeOptimal(int n) {
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) cout<<i<<" ";

        while(n%i == 0) {
            n = n/i;
        }
    }

    if(n!= 1) cout<<n<<endl;
}

int main() {
    // PrintPrime(780);
    PrintPrimeOptimal(780);
    return 0;
} 