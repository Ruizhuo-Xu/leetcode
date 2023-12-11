#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        while (--size) {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};

int main() {
    MyStack obj = MyStack();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    int res = obj.pop();
    cout << res << endl;
    res = obj.top();
    cout << res << endl;
    obj.pop();
    obj.pop();
    cout << obj.empty() << endl;
    return 0;
}