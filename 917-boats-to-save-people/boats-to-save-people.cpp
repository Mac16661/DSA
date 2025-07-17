class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i =0, j = people.size()-1, boatCnt = 0;
        while(i<=j) {
            // we are using if instead of while because of people[i] <= limit means limit will not exceed max(people idx 0->n)
            if(people[i] + people[j] <= limit) i++;
            j--;
            boatCnt++;
        } 

        return boatCnt;
    }
};