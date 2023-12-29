#include <iostream>
#include <vector>
using namespace std;

// 01背包问题理解: 每个物体(二维数组的纵轴)都有取或不取两种可能
// 每种可能都会引起背包状态(背包的容量)的变化(二维数组的横轴)
// 综合每种状态变化产生的实际结果(题目所需的输出),就是dp数组每个元素的值
int maxValue(int totalWeight, vector<int>& weights, vector<int>& values) {
    // 01背包问题
    // dp[i][j] 表示0-i件物品中任取若干件放入背包空间为j的背包,拥有的最大价值
    // 递推式: dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i])
    // 解释: 对于空间为j的背包,物品i有放或不放两种状态:
    // 放: 背包空间减小为 j - weights[i], 此时最大的价值为将0-(i-1)件物品任取放入j-weights[i]的背包的最大价值 + 当前物品的价值values[i]
    // 不放: 价值就等于将0-(i-1)件物品任取放入空间j的背包的价值dp[i - 1][j]
    // 初始化: 第一列都初始化为0(背包空间为0,无法放入任何东西),第一行根据物品重量和背包空间判断是否初始化为物品0的价值,其余位置无所谓
    // 遍历顺序: 先遍历物品后遍历背包空间,或反之也可以
    vector<vector<int>> dp(weights.size(), vector<int>(totalWeight + 1, 0));
    // 可以不用写
    // for (int i = 0; i < weights.size(); i++) {
    //     dp[i][0] = 0;
    // }
    for (int i = weights[0]; i <= totalWeight; i++) {
        dp[0][i] = values[0];
    }
    for (int i = 1; i < weights.size(); i++) {
        for (int j = 1; j <= totalWeight; j++) {
            int temp = 0;
            if (j - weights[i] >= 0) {
                temp = dp[i - 1][j - weights[i]] + values[i];
            }
            dp[i][j] = max(dp[i - 1][j], temp);
        }
    }
    return dp[weights.size()-1][totalWeight];
}

int maxValue_(int totalWeight, vector<int> weights, vector<int> values) {
    // 使用滚动数组,相当于把dp[i - 1]拷贝到dp[i]这一行,把二维数组压缩成一个一维数组
    vector<int> dp(totalWeight + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = totalWeight; j >= weights[i]; j--) { // 注意这里要倒序遍历,这样才符合滚动数组的含义,否则会重复选用同一个问题计算价值
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[totalWeight];
}

int main() {
    int m = 0;
    int n = 0;
    cin >> m >> n;
    vector<int> weights(m, 0);
    vector<int> values(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> values[i];
    }
    cout << maxValue_(n, weights, values);
    return 0;
}