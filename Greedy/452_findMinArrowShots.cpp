#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_ {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // 自己思考的版本,便于理解,代码冗余
        // 局部最优:尽可能多的寻找重叠的气球
        // 全局最优:用尽可能少的箭射完气球
        sort(points.begin(), points.end(), compare); // 按start排序
        int res = 1;
        vector<int> prePoint = {points[0][0], points[0][1]}; // 记录上一个交集的范围
        for (int i = 1; i < points.size(); i++) {
            int start = max(prePoint[0], points[i][0]); // 交集开始的位置
            int end = min(prePoint[1], points[i][1]); // 交集结束的位置
            if (start <= end) { // 判断当前这个气球的范围是否和上一个交集存在交集
                // 存在交集,说明只需要一支箭就可以消除,所以直接continue,不执行res++
                prePoint[0] = start;
                prePoint[1] = end;
                continue;
            } else {
                // 不存在交集,则更新当前气球的范围为新的交集,继续和下一个气球求交集
                prePoint[0] = points[i][0];
                prePoint[1] = points[i][1];
            }
            res++; // 不存在交集则需要一只新的箭来消除该气球
        }
        return res;
    }
};

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // 题解代码精简版本
        sort(points.begin(), points.end(), compare);
        int res = 1; // 初始化1只箭
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) { // 当前区间左边界大于上一个区间的右边界,说明不重叠
                res++; // 不重叠需要一只箭
            } else {
                points[i][1] = min(points[i][1], points[i - 1][1]); // 重叠不需要新的箭,更新重叠区间
            }
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    cout << Solution().findMinArrowShots(points) << endl;
    return 0;
}