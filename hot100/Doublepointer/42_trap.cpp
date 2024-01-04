#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 1) return 0;
        int left = 0;
        int right = 1;
        int sum = 0;
        while (right < height.size()) {
            if (height[left] <= height[right]) {
                left++;
                right++;
                continue;
            } else {
                int temp = 0;
                while (right < height.size() && height[left] > height[right]) {
                    temp += (height[left] - height[right]);
                    right++;
                }
                if (right != height.size()) {
                    cout << temp << endl;
                    sum += temp;
                }
                left = right;
                right++;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(height) << endl;
    return 0;
}