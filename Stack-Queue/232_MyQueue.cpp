#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stackIn;
    stack<int> stackOut;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if (stackOut.empty()) { // stackOut为空才开始将stackIn里的元素转移到Out,否则顺序有误
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int res = stackOut.top();
        stackOut.pop();
        return res;
    }
    
    int peek() {
       int res = pop();
       stackOut.push(res);
       return res;
    }
    
    bool empty() {
        if (stackIn.empty() && stackOut.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    int a = obj.pop();
    cout << a << endl;
    int b = obj.peek();
    cout << b << endl;
    obj.pop();
    // obj.pop();
    cout << obj.empty() << endl;
    return 0;
}