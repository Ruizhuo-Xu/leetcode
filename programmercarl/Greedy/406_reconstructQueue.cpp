#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) { // 要加static
        if (a[0] == b[0]) return a[1] < b[1]; // 身高相同,按k升序排序
        return a[0] > b[0]; // 按身高降序排序
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            list<vector<int>>::iterator it = que.begin();
            while (position--) {
                it++; // list需要通过迭代器++的形式找到插入的位置
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

int main() {
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> res = Solution().reconstructQueue(people);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ',';
        }
        cout << endl;
    }
    return 0;
}