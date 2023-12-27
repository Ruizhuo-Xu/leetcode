#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size());
        candyVec[0] = 1; // 从左往右遍历,如果当前孩子的评分大于左边孩子的评分,则比左边孩子多分一个糖果,否则只分一个糖果
        for (int i = 1; i < ratings.size(); i++) {
            candyVec[i] = (ratings[i] > ratings[i - 1]) ? candyVec[i - 1] + 1 : 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) { // 从右往左遍历,如果当前孩子的评分大于右边孩子的评分,则比右边孩子多分一个糖果,否则只分一个
            int temp = (ratings[i] > ratings[i + 1]) ? candyVec[i + 1] + 1 : 1;
            candyVec[i] = max(temp, candyVec[i]); // candyVec[i]只有取最大的才能既保持对左边candyVec[i - 1]的糖果多，也比右边candyVec[i + 1]的糖果多
        }
        int res = 0;
        for (int it : candyVec) res += it;
        return res;
    }
};

int main() {
    vector<int> ratings = {1,2,2};
    cout << Solution().candy(ratings) << endl;
    return 0;
}