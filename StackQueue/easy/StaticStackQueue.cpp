#include <bits/stdc++.h>
using namespace std;

// STATIC MEMORY IMPLEMENTATION [ARRAYS]

/// @brief O(1)time and O(n) space
class StackImplementation
{
private:
    int topIndex = -1;
    int st[10];

public:
    void push(int x)
    {
        if (topIndex >= 9)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        topIndex++;
        st[topIndex] = x;
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack underflow" << endl;
            return -1; // Return a placeholder value
        }
        return st[topIndex];
    }

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack empty" << endl;
            return;
        }
        topIndex--;
    }

    int size()
    {
        return topIndex + 1;
    }
};

/// @brief O(1)time and O(n) space
class QueueImplementation
{
private:
    int size = 10;
    int q[10];
    int currSize = 0;
    int start = -1;
    int end = -1;

public:
    void push(int x)
    {
        if (currSize == size)
        {
            return;
        }

        if (currSize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % size;
        }

        q[end] = x;
        currSize = currSize + 1;
    }

    int pop()
    {
        if (currSize == 0)
        {
            return -1;
        }

        int element = q[start];

        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % size;
        }

        currSize -= 1;
        return element;
    }

    int top()
    {
        if (currSize == 0)
        {
            return -1;
        }

        return q[start];
    }

    int Qsize()
    {
        return currSize;
    }
};


int main()
{
    // Storing it in stack memeory
    StackImplementation stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Get the size of the stack
    cout << "Stack size: " << stack.size() << endl;

    // Peek at the top element
    cout << "Top element: " << stack.top() << endl;

    // Pop the top element
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    // Final stack size
    cout << "Stack size after pop: " << stack.size() << endl;

    // Storing it in dynamic or heap memory

    QueueImplementation *qu = new QueueImplementation();

    qu->push(5);
    qu->push(2);
    qu->push(3);
    qu->push(4);

    cout << qu->top() << endl;
    cout << qu->Qsize() << endl;

    cout << qu->pop() << endl;

    return 0;
}