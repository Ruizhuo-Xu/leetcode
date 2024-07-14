#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, int nodeIdx) {
        if (nodeIdx == graph.size() - 1) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < graph[nodeIdx].size(); i++) {
            path.push_back(graph[nodeIdx][i]);
            dfs(graph, graph[nodeIdx][i]);
            path.pop_back();
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;  // nodes: m, edges: n
    vector<vector<int>> graph(m);
    while (n--) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);  // i -> j
    }
    vector<vector<int>> res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int x : path) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}