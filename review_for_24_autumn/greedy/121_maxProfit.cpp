#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - prices[i - 1];
            sum += profit;
            if (sum < 0) {
                sum = 0;
            } 
            res = max(res, sum);
        }
        return res;
    }
};