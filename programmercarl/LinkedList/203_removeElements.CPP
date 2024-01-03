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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(); // 虚拟头节点
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp; // 手动释放被删除节点的内存
            } else { // 注意这里需要else
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead; // 释放虚拟头节点的内存
        return head;
    }
};

int main() {
    int x[7] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (auto it : x) {
        cur->next = new ListNode();
        cur = cur->next;
        cur->val = it;
    }
    int val = 6;
    Solution so = Solution();
    cur = so.removeElements(dummyHead->next, val); // 返回新的头节点
    while (cur != nullptr) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}