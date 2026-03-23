class MyQueue {
    stack<int> st1; // push here
    stack<int> temp; 

public:
    MyQueue() {}
    
    void push(int x) {
        while(!st1.empty()) {
            temp.push(st1.top());
            st1.pop();
        }

        st1.push(x); // inserting at bottom to maintain FIFO order

        while(!temp.empty()) {
            st1.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int top = st1.top();
        st1.pop();
        return top;
    }
    
    int peek() {
        if(!st1.empty()) return st1.top();
        else return -1;
    }
    
    bool empty() {
        return st1.empty() && temp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */