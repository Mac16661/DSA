#include<bits/stdc++.h>
using namespace std;

void isValid(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
        else{
            if(st.empty()) {
                cout<<"Valid parentheses"<<endl;
                return;
            }
            char curr = st.top();
            if((curr=='(' && s[i]==')') or (curr=='[' && s[i]==']') or (curr=='{' && s[i]=='}')) st.pop();
            else st.push(s[i]);
        }
    }

    if(st.empty()){
        cout<<"Valid parentheses"<<endl;
        return;
    }
    cout<<"Invalid parentheses"<<endl;
}

int main() {
    
    string s2= "()[{}(])";
    string s1= "()[{}()]";

    isValid(s1);
    isValid(s2);

    return 0;
}