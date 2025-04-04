class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int i:nums){
            if(i<0){ //neg
                neg.push_back(i);
            }else{ //pos
                pos.push_back(i);
            }
        }

        int i=0;
        int j=0;

        while(i<pos.size()) {
            nums[j] = pos[i];
            nums[j+1] = neg[i];
            i++;
            j+=2;
        }

        return nums;
    }
};