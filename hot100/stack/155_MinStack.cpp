#include <iostream>
#include <cstdint>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> valSt;
    stack<int> minSt;
public:
    MinStack() {
        minSt.push(INT32_MAX);
    }
    
    void push(int val) {
        valSt.push(val);
        minSt.push(min(minSt.top(), val)); // 比较之前最小的元素和当前值,取最小的入栈
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