class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> t;
        if(numRows == 0) return t;

        t.push_back({1});
        if(numRows == 1) {
            return t;
        }

        for(int i = 1; i<numRows; i++) {
            vector<int> temp;
            temp.push_back(1);

            // for middle numbers
            for(int j=1; j<i; j++){
                int a = t[i-1][j-1];
                int b = t[i-1][j];

                temp.push_back(a+b);
            }

            temp.push_back(1);
            t.push_back(temp);
        }

        return t;
    }
};