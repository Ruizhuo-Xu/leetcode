#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> outDegree(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++;
            outDegree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> que;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }
        int cnt = 0;
        while (!que.empty()) {
            cnt++;
            int course = que.front();
            que.pop();
            for (int i = 0; i < outDegree[course].size(); i++) {
                inDegree[outDegree[course][i]]--;
                if (inDegree[outDegree[course][i]] == 0) {
                    que.push(outDegree[course][i]);
                }
            }
        }
        return cnt == numCourses;
    }
};