#include<bits/stdc++.h>
using namespace std;

int SumOfN(int N) {
    if(N <= 0) return 0;

    return (N + SumOfN(N-1));
}

int main() {
    cout<< "Sum of N -> "<<SumOfN(5)<<endl;
    return 0;
}