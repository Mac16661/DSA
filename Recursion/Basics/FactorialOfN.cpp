#include<bits/stdc++.h>
using namespace std;

int factorial(int N) {
    if(N <= 1) return 1;

    return (N * factorial(N-1));
}

int main() {
    cout<<"Factorial -> "<<factorial(5)<<endl;
    return 0;
}