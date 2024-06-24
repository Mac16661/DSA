#include<bits/stdc++.h>
using namespace std;

//TODO: In order to print all the values we need to put it in a set in case of recursion
int Fib(int n) {
    if(n <= 1) return 0;

    if(n == 2) return 1;

    int last = Fib(n-1);
    int slast = Fib(n-2);
 
    // cout<<last+slast<<" ";
    return (last+slast);
}

int main() {
    cout<<"Fibonachi No -> "<<Fib(8)<<endl;
    return 0;
}