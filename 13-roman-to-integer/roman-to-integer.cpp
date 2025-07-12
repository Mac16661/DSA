class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(); int sum = 0;
        unordered_map<string, int> mpp {
            {"I", 1}, {"V",5}, {"X", 10} ,{"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4},
             {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
        };

        for(int i=n-1; i>=0; i--) {
            string t;
            if(i > 0){
                t = string(1, s[i-1]) + s[i];
            }

            if(mpp.find(t) != mpp.end()){
                sum += mpp[t];
                i--;
            }else{
                sum += mpp[string(1, s[i])];
            }
        }

        return sum;
    }
};