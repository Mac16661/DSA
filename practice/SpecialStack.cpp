#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class SpecialStack{
        int top;
        int min;

    public:
        int arr[MAX];

        SpecialStack() {
            top = -1;
            min = INT_MAX;
        }

        bool push(int x) {
            if(top >= MAX - 1) {
                cout<<"Stack Overflow\n";
                return false;
            }else{
                if(x < min) {
                    min = x;
                }

                arr[top++] = x; 
                return true;
            }
        }

        int pop() {
            if(top < 0) {
                cout<<"Stack Underflow\n";
                return -1;
            }
            return arr[top--];
        }

        int getMin() {
            return min;
        }

        int peek() {
            if(top < 0) {
                cout<<"Stack is empty\n";
                return -1;
            }
            return arr[top];
        }

        bool isEmpty(){
            return top < 0;
        }

};

int main() {
    SpecialStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.getMin()<<endl;

    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}