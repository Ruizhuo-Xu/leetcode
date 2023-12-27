#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 小饼干优先分配给小胃口的孩子
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0; // 胃口索引
        int res = 0;
        for (int i = 0; i < s.size(); i++) { // 遍历饼干
            if (index < g.size() && g[index] <= s[i]) { // 注意边界条件index < g.size()
                res++;
                index++;
            } else if (index >= g.size()) { // 剪枝
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<int> g = {1, 2, 7, 10}; // 胃口
    vector<int> s = {1, 3, 5, 9}; // 饼干
    int res = Solution().findContentChildren(g, s);
    cout << res << endl;
    return 0;
}