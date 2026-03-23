class Solution {
public:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;

        return false;
    }
    int maxVowels(string s, int k) {
        // brute ->
        // int maxi = 0;
        // for(int i=0; i<s.size(); i++) {
        //     int cnt=0;
        //     for(int j=i; j<i+k && j<s.size(); j++) {
        //         if(isVowel(s[j])) cnt++;
        //         cout<<s[j]<<" ";
        //     }
        //     cout<<endl;
        //     maxi = max(maxi, cnt);
        // }
        // return maxi;

        // better nlogn

        // optimal
        int l=0;
        int r=0;
        int maxV = 0;
        int cnt=0;

        while(r<s.size()) {
            if(isVowel(s[r])) cnt++;

            if(r-l+1 > k) {
                if(isVowel(s[l])) cnt--;
                l++;
            }

            maxV = max(maxV, cnt);
            r++;
        }

        return maxV;

    }
};