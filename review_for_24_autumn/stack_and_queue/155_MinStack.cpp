#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> valSt;
    stack<int> minSt;
    MinStack() {
        minSt.push(INT32_MAX);
    }
    
    void push(int val) {
        valSt.push(val);
        minSt.push(min(minSt.top(), val));
    }
    
    void pop() {
        valSt.pop();
        minSt.pop();
    }
    
    int top() {
        return valSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};