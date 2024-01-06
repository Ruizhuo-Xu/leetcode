#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 贪心, 时间复杂度O(nlogn),空间复杂度O(logn) // 排序的开销
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        for (int i = 1; i <= intervals.size(); i++) {
            if (i != intervals.size() && intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i - 1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = Solution().merge(intervals);
    for (auto interval : res) {
        for (int i : interval) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}