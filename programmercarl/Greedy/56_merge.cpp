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

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res;
        for (int i = 1; i <= intervals.size(); i++) { // <=是为了把最后一个区间结果也考虑在内
            if (i == intervals.size() || intervals[i][0] > intervals[i - 1][1]) { // 当前区间和上个区间不重叠,结果加入上个区间
                // 最后一个区间直接加入结果
                res.push_back(intervals[i - 1]);
            } else { // 有重叠,更新重叠的区间,注意求的是并集,和之前的题目不一样
                intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = Solution().merge(intervals);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}