#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // https://leetcode.cn/problems/course-schedule/solutions/250377/bao-mu-shi-ti-jie-shou-ba-shou-da-tong-tuo-bu-pai-
        vector<int> inDegree(numCourses, 0); // 入度数组
        unordered_map<int, vector<int>> mp; // key: 先修课程 value: 依赖key的课程
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++; // 需要先修课程的课入度+1
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]); // 也可以理解为记录每门课程的出度
        }
        queue<int> que;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                que.push(i); // 将不需要先修课程的课入队
            }
        }
        int count = 0;
        while (!que.empty()) {
            int course = que.front();
            que.pop();
            count++;
            for (int i = 0; i < mp[course].size(); i++) {
                inDegree[mp[course][i]]--;
                if (inDegree[mp[course][i]] == 0) {
                    que.push(mp[course][i]);
                }
            }
        }
        return count == numCourses;
    }
};

int main() {
    int numCourses = 6;
    vector<vector<int>> pre = {{3, 0}, {3, 1}, {4, 1}, {4, 2}, {5, 3}, {5, 4}};
    cout << Solution().canFinish(numCourses, pre) << endl;;
    return 0;
}