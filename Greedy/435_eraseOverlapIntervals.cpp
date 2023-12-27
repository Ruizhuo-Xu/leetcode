#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 局部最优:存在重叠时,删除右边界大的区间
        // 全局最优:删除最少的区间,使所有的区间都不重叠
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) { // 不重叠
                continue;
            }
            // if (intervals[i][1] <= intervals[i - 1][1]) { // 当前区间被上一个区间包含, 删除范围大的区间,保留当前区间
            //     res++;
            // } else { // 当前区间的右边界 > 上一个区间的右边界, 删除当前区间
            //     res++;
            //     intervals[i][1] = intervals[i - 1][1];
            // }

            // 上面的两种情况可以用下面的代码简化
            intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]); // 模拟删除区间
            res++; // 存在重叠就删除一个区间
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << Solution().eraseOverlapIntervals(intervals) << endl;
    return 0;
}