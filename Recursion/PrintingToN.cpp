#include<bits/stdc++.h>
using namespace std;

void PrintN(int n) {
    if(n < 0) return;

    cout<<"Subhodip "<<endl;

    PrintN(n-1);
}

int main() {
    PrintN(5);
    return 0;
}