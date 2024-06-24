#include<bits/stdc++.h>
using namespace std;

int PowX(int x, int n) {
    if(n < 2) return x;

    return x * PowX(x, n-1);

}

int main() {
    cout<<PowX(2,6)<<endl;
    return 0;
}