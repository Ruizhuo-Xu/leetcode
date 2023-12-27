#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) { // 今明两天的股价存在正差价,则今天购入,明天售出(局部最优)
                profit += (prices[i + 1] - prices[i]);
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int res = Solution().maxProfit(prices);
    cout << res << endl;
    return 0;
}