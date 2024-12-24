//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        dataStack.push(val);
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;   
    cout << minStack.getMin() << endl;

    return 0;
}
