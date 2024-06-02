#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    // string s = "12";
    // int x = stoi(s);
    // cout << sizeof(x) << ' ' <<  stoi(s) << endl; // stirng->int
    // cout << to_string(x) << endl; // int -> string
    // string s = "hello";
    // cout << s.substr(2, 3) << endl;
    // int a = 3 ^ 2 ^ 3;
    // cout << a << endl;
    // unordered_set<int> set;
    // set.insert(1);
    // queue<int> que;
    // for (int i = 0; i < 5; i++) {
    //     que.push(i);
    // }
    // cout << que.front() << ' ' << que.back() << endl;
    // deque<int> que;
    // que.
    vector<int> nums(5);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
