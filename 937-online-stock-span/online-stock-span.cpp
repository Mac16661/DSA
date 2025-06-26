class StockSpanner {
public:
    stack<pair<int, int>> st; // pair<price, index>
    int ind;

    StockSpanner() {
        ind = -1;
        while (!st.empty()) st.pop(); // or just leave st as-is; constructor handles it
    }
    
    int next(int price) {
        ind = ind + 1; // keeping track of the index

        // Pop prices that are less than or equal to the current one
        while (!st.empty() && st.top().first <= price)
            st.pop();

        int ans = ind - (st.empty() ? -1 : st.top().second);

        st.push({price, ind});

        return ans;
    }
};
