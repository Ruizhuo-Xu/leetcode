#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) { // 维持一个单调递增栈
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> res = Solution().dailyTemperatures(temperatures);
    for (auto num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}