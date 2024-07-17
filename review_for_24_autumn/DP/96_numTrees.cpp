#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i]: i个不同数可以组成的二叉搜索树的个数
        // dp[i] += dp[j - 1]dp[i - j], j=1,...,i  相当于从1-i依次作为根节点，左子树的个数为dp[j - 1],右子树的个数为dp[i - j]
        // dp[0] = 1;
        // i从1开始遍历到n，j从1开始遍历到i
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) { // 因为节点从1开始
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};