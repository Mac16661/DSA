class Solution {
public:
    struct absDist {
        int a;
        int b;
        int absdist;

        absDist(int x, int y, int dist){
            a=x;
            b=y;
            absdist=dist;
        }
    };
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        for(auto cost:costs) cout<<cost[0]<<" "<<cost[1]<<endl;

        int price = 0;
        int n = costs.size();
        for(int i = 0; i < costs.size() / 2; i++){
            price += costs[i][0] + costs[n-1-i][1];
        }

        return price;
    }
};