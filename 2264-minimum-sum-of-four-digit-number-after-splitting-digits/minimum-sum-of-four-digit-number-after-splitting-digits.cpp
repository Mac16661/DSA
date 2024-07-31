class Solution {
public:
    int minimumSum(int num) {
        string n = to_string(num);
        // string num1 = n.substr(0,2);
        // string num2 = n.substr(2,n.size());

        // // cout<<num1<<endl<<num2<<endl;

        // sort(num1.begin(), num1.end());
        // sort(num2.begin(), num2.end());

        // int sum = stoi(num1);
        
        // sum += stoi(num2);

        sort(n.begin(), n.end());

        string num1 = string(1,n[0])+ string(1,n[3]);
        string num2 = string(1,n[1])+ string(1,n[2]);

        int sum = stoi(num1)+stoi(num2);

        return sum;
    }
};