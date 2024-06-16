#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建一个虚拟头节点，使用new返回指针
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead;
        while (n--) {
            cur = cur->next;
        }
        while (cur->next != nullptr) {  // cur移动到链表末尾, 此时cur为倒数第一个节点，pre为倒数第n+1个节点, pre->next为要删除的节点
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        return dummyHead->next;
    }
};