#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> dp(i, 1);
            for (int j = 1; j < i - 1; j++) {
                int idx = res.size() - 1;
                dp[j] = res[idx][j - 1] + res[idx][j];
            }
            res.push_back(dp);
        }
        return res;
    }
};