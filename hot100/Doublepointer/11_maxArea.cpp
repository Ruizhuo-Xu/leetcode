#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 时间复杂度O(n), 时间复杂度O(1)
        // 初始化双指针一个在数组开头，一个在数组末尾
        // 短板向内移动, 长板保持不动
        // 因为长板向内移动不可能取得更大的值
        int left = 0;
        int right = height.size() - 1;
        int maxVal = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            maxVal = max(maxVal, area);
            height[left] < height[right] ? left++ : right--; // 短板向内移动
        }
        return maxVal;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}