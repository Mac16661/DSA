class Solution {
public:
    bool isSorted(string s){
        for(int i=1;i<s.length();i++){
            if(s[i]<s[i-1])return false;
        }
        return true;
    }
    int minOperations(string s) {
        int n=s.length();
        if(isSorted(s))return 0;
        if(n==2)return -1;
        char minChar='z',maxChar='a';
        for(int i=0;i<n;i++){
            char currChar=s[i];
            minChar=min(minChar,currChar);
            maxChar=max(maxChar,currChar);
        }
        if(minChar==s[0] || maxChar==s[n-1])return 1;
        string one=s,two=s;
        //1+2
        sort(begin(one),begin(one)+n-1);
        sort(begin(one)+1,end(one));
        // 2+1
        sort(begin(two)+1,end(two));
        sort(begin(two),begin(two)+n-1);
        if(isSorted(one) || isSorted(two))return 2;
        return 3;
    }
};