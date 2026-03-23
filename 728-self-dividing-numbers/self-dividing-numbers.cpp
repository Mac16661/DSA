class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int i=left; i<=right; i++) {

            string s = to_string(i);
            bool is = true;
            for(int j=0; j<s.size(); j++) {
                int ch = s[j] - '0';
                // cout<<ch<<endl;
                if(ch == 0) {
                    is = false;
                    break;
                } else if(i% ch != 0){
                    is = false;
                    break;
                } 
            }     

            if(is) ans.push_back(i);       
            
        }

        return ans;
    }
};