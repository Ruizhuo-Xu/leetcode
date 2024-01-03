#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i] 表示i个结点可以组成的二叉搜索树的数量
        // 递推公式: dp[i] += dp[j - 1] * dp[i - j], j = 1,...,i
        // 初始化: dp[0] = 1;
        // 遍历: 从前往后
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) { // 1-i依次作为根结点,左子树的结点数为j - 1,右子树的结点数为i-j
                dp[i] += dp[j - 1] * dp[i - j]; // 左子树可能的情况 * 右子树可能的情况 = 总的情况
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numTrees(3);
    return 0;
}