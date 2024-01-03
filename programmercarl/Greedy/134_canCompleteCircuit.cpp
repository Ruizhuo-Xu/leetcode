#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 局部最优: 按顺序寻找可以出发的加油站(油量有剩余),如果出发后中途油量不够,则从下一个加油站开始继续寻找
        // 之所以可以从下一个加油站开始寻找是因为在遇到油量不够的加油站前剩余的油量都是大于等于0的,所以不管从之前的那一站出发剩余油量只会更少
        // 全局最优: 找到可以完整跑完一圈的出发点
        for (int i = 0; i < gas.size(); i++) {
            int rest = gas[i] - cost[i]; // 记录当前站出发后剩余的油量
            if (rest < 0) { // 从当前加油站出发无法到达下一站,则不出发
                continue;
            }
            // 从当前加油站出发可以到达下一站,则从当前站开始往后行驶
            int index = (i + 1) % gas.size(); // 因为是循环,所以要取余
            while (index != i) { // index == i 说明完成了一圈,又回到了起点
                rest += (gas[index] - cost[index]);
                if (rest < 0) { // 无法到达下一站
                    if (index > i) i = index; // 如果该站的位置再i之后,则从下一个位置(for循环i还会++)继续寻找合适的出发站
                    else if (index <= i) return -1; // 如果该站的位置在i之前,则说明肯定无法完成一圈(因为在之前的循环中已经判断过了)
                    break;
                }
                index = (index + 1) % gas.size(); // 更新下一站索引
            }
            if (rest >= 0) { // 如果油量还有剩余,则说明完成了一圈
                return i;
            }
        }
        return -1;
    }
};

int main() {
    // vector<int> gas = {1,2,3,4,5};
    // vector<int> cost = {3,4,5,1,2};
    vector<int> gas = {5,8,2,8};
    vector<int> cost = {6,5,6,6};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}