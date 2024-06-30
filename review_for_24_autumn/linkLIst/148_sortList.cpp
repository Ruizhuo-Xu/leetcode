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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        return mergeSort(head, nullptr);
    }

    ListNode* mergeSort(ListNode* head, ListNode* tail) { // 左闭右开
        if (head->next == tail) { // 左闭右开的情况下说明只有一个节点
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* h1 = mergeSort(head, slow);
        ListNode* h2 = mergeSort(slow, tail);
        return merge(h1, h2);
    }

    ListNode* merge(ListNode* h1, ListNode* h2) { // 合并两个有序列表
        ListNode* dummyHead = new ListNode();
        ListNode* cur1 = h1;
        ListNode* cur2 = h2;
        ListNode* cur = dummyHead;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                cur->next = new ListNode(cur1->val);
                cur1 = cur1->next;
            } else {
                cur->next = new ListNode(cur2->val);
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1 != nullptr) {
            cur->next = cur1;
        }
        if (cur2 != nullptr) {
            cur->next = cur2;
        }
        return dummyHead->next;
    }
};