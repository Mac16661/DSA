#include<bits/stdc++.h>
class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        string temp1 = to_string(num);

        char isSet = '\n';
        // make large digit
        for(int i=0; i<temp.size(); i++) {
            if(temp[i]!='9' && isSet=='\n') {
                isSet = temp[i];
                temp[i]='9';
            }else if(temp[i] == isSet) {
                temp[i] = '9';
            }
        }

        //make small digit
        isSet = '\n';
        for(int i=0; i<temp.size(); i++) {
            if(temp1[i]!='0' && isSet=='\n') {
                isSet = temp1[i];
                temp1[i]='0';
            }else if(temp1[i] == isSet) {
                temp1[i] = '0';
            }
        }

        // cout<<temp<< " "<<temp1;
        return stoi(temp) - stoi(temp1);

    }
};