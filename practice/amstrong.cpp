#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 153;
    string temp = to_string(n);
    int newNum = 0;

    for(int i=0; i<temp.length(); i++) {
        int digit = temp[i] - '0'; // converting to integer
        newNum += pow(digit, temp.length());

    }
    // cout<<newNum;
    if(newNum == n){
        cout<<"AMSTRONG NO"<<endl;
    }else{
        cout<<"NOT AMSTRONG NO"<<endl;
    }
    
    return 0;
}