#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> res;
    unordered_map<string, map<string, int>> targets; // 起点: (终点: 航班数) map保证终点有序(升序)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> s : tickets) {
            targets[s[0]][s[1]]++;
        }
        int ticketsNums = tickets.size();
        res.push_back("JFK");
        backtracking(ticketsNums);
        return res;
    }

    bool backtracking(int ticketsNums) {
        if (ticketsNums + 1 == res.size()) { // 航班数 + 1 = 途径的飞机站的数量
            return true;
        }
        map<string, int>& target = targets[res.back()]; // 这里要用引用
        for (map<string, int>::iterator it = target.begin(); it != target.end(); it++) {
            if (it->second > 0) { // 还存在航班
                it->second--;
                res.push_back(it->first);
                if (backtracking(ticketsNums)) return true;
                res.pop_back();
                it->second++;
            }
        }
        return false; // 这里要return false; 因为上面的循环一直优先选择字母顺序靠前的站点,一旦该站点没有出去的航班就会到这里返回false，回溯
    }
};

int main() {
    // [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]] // return false起作用的例子
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res = Solution().findItinerary(tickets);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}