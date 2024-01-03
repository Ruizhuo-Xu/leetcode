#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 假设链表 dummyHead->1->2->3->4
        // 以第一次循环为例:cur = dummyHead;
        // step1: 交换两个节点cur->1->2->1, 使用临时变量tmp存储节点3
        // step2: cur->2->1;
        // step3: cur->2->1->tmp
        // step4: cur = cur->next->next
        ListNode* dummyHead = new ListNode(); // 虚拟头节点
        dummyHead->next = head; // 将虚拟头节点加入链表
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next->next->next;
            cur->next->next->next = cur->next;
            cur->next = cur->next->next;
            cur->next->next->next = tmp;
            cur = cur->next->next; // 更新cur
        }
        return dummyHead->next;
    }
};

int main() {
    int x[4] = {1, 2, 3, 4};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (auto it : x) {
        cur->next = new ListNode();
        cur = cur->next;
        cur->val = it;
    }
    Solution so = Solution();
    dummyHead->next = so.swapPairs(dummyHead->next);
    cur = dummyHead;
    while (cur->next != nullptr) {
        cout << cur->next->val << ' ';
        cur = cur->next;
    }
    return 0;
}