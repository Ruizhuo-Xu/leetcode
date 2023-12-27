#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0; // 分别记录拥有的5元和10元的个数
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) fiveCount++; // 收到5元,不用找零
            if (bills[i] == 10) { // 收到10元,如果有5元就找开,没有5元就找不开
                tenCount++;
                if (fiveCount) fiveCount--;
                else return false;
            }
            if (bills[i] == 20) { // 收到20元,优先判断是否可以用10+5的组合找开,因为10元可以用两张5元组成,所以5元更重要
                if (tenCount && fiveCount) {
                    tenCount--;
                    fiveCount--;
                } else if (fiveCount >= 3) { // 如果没有十元,判断能否用3张5元找开
                    fiveCount -= 3;
                } else { // 如果有10元没有5元,或既没有10元也没有足够的5元,则无法找开
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5,5,5,10,20};
    cout << Solution().lemonadeChange(bills) << endl;
    return 0;
}