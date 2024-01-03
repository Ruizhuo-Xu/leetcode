#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // strs中每个元素有取与不取两种可能,每种可能会引起背包状态的改变(0, 1的数量)
        // 需要求0, 1数量为m和n时背包能装的最多的物品数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp数组初始化为0
        for (string str : strs) {
            int x = 0, y = 0; // 当前字符串中0和1的数量
            for (char ch : str) {
                if (ch == '0') x++;
                else y++;
            }
            for (int j = m; j >= x; j--) {
                for (int k = n; k >= y; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1); // dp[j][k]表示0和1数量为j和k的背包所能装的(0 - i)中最多的物品数
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << Solution().findMaxForm(strs, 5, 3) << endl;;
    return 0;
}