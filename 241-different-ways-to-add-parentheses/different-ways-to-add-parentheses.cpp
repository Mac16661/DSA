class Solution {
public:
    // Recursive solution using expression trees
    int perform(int x, int y, char op) {
        if(op=='+') return x+y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }

    vector<int> diffWaysToCompute(string exp) {
        vector<int> results;
        bool isNumber = 1;

        for(int i=0; i<exp.length(); i++) {
            // check if digit
            if(!isdigit(exp[i])) {
                isNumber = 0;

                vector<int> left = diffWaysToCompute(exp.substr(0,i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));

                for(auto x:left) {
                    for(auto y:right) {
                        int val = perform(x,y,exp[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        if(isNumber==1) results.push_back(stoi(exp));
        return results;   
    }
};