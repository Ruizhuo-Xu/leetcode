#include <iostream>
using namespace std;

int main() {
    // cout << "hello world" << endl;
    string s = "abc";
    cout << s.size() << endl; 
    s.resize(s.size() * 2);
    cout << s.size() << endl;
    return 0;
}