class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string op = to_string(k);
        int i = op.size()-1;
        int j = num.size()-1;
        int carry = 0;
        string ans = "";

        while(i>=0 || j>=0 || carry!=0) {
            int sum = carry;
            carry = 0;

            if(i>=0) sum+= op[i]-'0';
            if(j>=0) sum+= num[j];

            ans = to_string(sum%10) + ans;
            carry = sum/10;
            i--;
            j--;
        }

        vector<int> finalans;
        for(int i=0; i<ans.size(); i++) {
            // cout<<ans[i]<<" ";
            finalans.push_back(ans[i]-'0');
        }

        return finalans;
    }
};