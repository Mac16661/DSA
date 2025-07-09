class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        
        int l=0;
        int r=0;

        int maxi = 0;

        while(r < fruits.size()) {
            // push fruits[r] into mpp
            mpp[fruits[r]]++;

            // we need to check how many index in the map if > 2 start increment left ptr and remove mpp[fruits[l]]-- and if mpp[fruits[l]] == 0. run it until mpp.size() == 2
            while(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] <= 0) mpp.erase(fruits[l]);   
                l++;
            }

            // calculate length of window 
            maxi = max(maxi, r - l + 1);

            // increment r
            r++;
        }

        return maxi;
    }
};