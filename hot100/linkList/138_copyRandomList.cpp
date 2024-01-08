#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {};
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 给链表中的每个节点赋予一个下标
        // 使用一个map记录 节点指针:下标
        // 使用一个vector,储存深拷贝的链表
        // 时间复杂度O(n),空间复杂度O(n)
        unordered_map<Node*, int> mp;
        Node* cur = head;
        int index = 0;
        while (cur != nullptr) {
            mp[cur] = index++;
            cur = cur->next;
        }
        mp[cur] = index++;
        vector<Node*> vec(mp.size(), nullptr);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // 第一遍遍历,先创建各个节点
            if (it->first != nullptr) {
                vec[it->second] = new Node(it->first->val);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // 第二遍遍历,给每个节点的next和random赋值
            if (it->first != nullptr) {
                vec[it->second]->next = vec[it->second + 1];
                vec[it->second]->random = vec[mp.find(it->first->random)->second];
            }
        }
        return vec[0];
    }
};

int main() {
    // vector<
}