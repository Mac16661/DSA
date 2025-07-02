class Solution {
public:
    vector<int> NSE(vector<int>& price) {
        int n = price.size();
        vector<int> nse(price.size(), -1);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() > price[i]){
                st.pop();
            }

            if(!st.empty()) nse[i] = st.top();

            st.push(price[i]);
        }

        return nse;
    }

    vector<int> finalPrices(vector<int>& prices) {
        vector<int> nse = NSE(prices); 

        // for(auto i:nse) cout<<i<<" ";
        // cout<<endl;  

        for(int i=0; i<prices.size(); i++) {
            if(nse[i] != -1 && nse[i] <= prices[i]){
                prices[i] = prices[i] - nse[i];
            }
        } 

        return prices;
    }
};