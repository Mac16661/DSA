class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i =0, j = n-1;
        int cnt = 0;
        sort(people.begin(), people.end());

        while(i<=j) {
            // cout<<people[i] <<" "<<people[j]<<endl;
            if(people[i] + people[j] > limit) {
                j--;
                cnt++;
            }else {
                i++;
                j--;
                cnt++;
            }
        }

        return cnt;
    }
};