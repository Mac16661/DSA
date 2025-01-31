// Use queue to implement stack
#include<bits/stdc++.h>
using namespace std;

// TODO: Doing it using single queue
// void Push(int x) {
//       int s = q.size();
//       q.push(x);
//       for (int i = 0; i < s; i++) {

//         q.push(q.front());
//         q.pop();
//       }
// }

class SuQ{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        // We can optimize for push ops if there are many push in our use case but that will make pop and top ops more costly
        void push(int x) {
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(x);

            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }

        int pop() {
            if(q1.empty()) return -1;
            int val = q1.front();
            q1.pop();
            return val;
        }

        int sizeOfSt() {
            return q1.size();
        }
};

int main() {
    SuQ st;

    st.push(1);
    // st.push(2);
    // st.push(3);

    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;

    return 0;
}