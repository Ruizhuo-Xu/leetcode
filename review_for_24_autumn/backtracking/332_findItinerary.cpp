#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> mp;  // 出发航班: (目标航班: 航班数) 这个数据结构是解题的关键
        for (int i = 0; i < tickets.size(); i++) {
            mp[tickets[i][0]][tickets[i][1]]++;
        }
        res.push_back("JFK");
        backtracking(tickets, mp);
        return res;
    }

    bool backtracking(vector<vector<string>>& tickets, unordered_map<string, map<string, int>>& mp) { // 因为找到符合条件的路径即退出,所以是bool类型
        if (res.size() == tickets.size() + 1) {
            return true;
        }
        string last = res[res.size() - 1];
        map<string, int>& airport = mp[last];  // 这里要用引用，否则下面无法更新真正的次数
        for (auto it = airport.begin(); it != airport.end(); it++) {
            if (it->second > 0) {
                it->second--;
                res.push_back(it->first);
                if (backtracking(tickets, mp)) {
                    return true;
                }
                res.pop_back();
                it->second++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res = Solution().findItinerary(tickets);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}