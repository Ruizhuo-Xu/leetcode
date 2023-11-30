#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 寻找最大子序列
        unordered_map<int, int> basket;
        int left = 0;
        int res = 0;
        int fruit_kinds = 0; // 水果种类
        for (int right = 0; right < fruits.size(); right++) {
            if (basket[fruits[right]] == 0) {
                fruit_kinds++;
            }
            basket[fruits[right]]++;
            while (fruit_kinds > 2) { // 不符合条件则移动左指针使其符合
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    fruit_kinds--;
                }
                left++;
            }
            int subLength = right - left + 1; // 只要符合条件就统计子序列长度
            res = subLength > res ? subLength : res;
        }
        return res;
    }
};

int main() {
    Solution so = Solution();
    vector<int> fruits = {1,2,3,2,2};
    cout << so.totalFruit(fruits) << endl;
    return 0;
}