#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 第j天买入股票，第i天卖出的获利profit[i, j] = prices[i] - prices[j]
        // 进一步推导：profit[i, j] = (prices[i] - prices[i - 1]) + ... + (prices[j + 1] - prices[j]);
        // 所以问题转换为profits数组的最大子数组和问题，profits数组是两天股价的差值
        // 最大子数组和问题: 不断累加数组元素，大于0就继续累加，并记录最大值，小于0则sum清0，从下一个数开始累加；
        int sum = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            sum += (prices[i] - prices[i - 1]);
            if (sum < 0) sum = 0;
            res = max(sum, res);
        }
        return res;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}