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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 题目要求不能修改原链表结构，所以不能翻转链表
        // 分别遍历A、B两个链表,确定各自的长度
        // 将两个链表右对齐,依次比较指针是否相同
        int sizeA = 0;
        int sizeB = 0;
        ListNode* cur = headA;
        while (cur != nullptr) {
            cur = cur->next;
            sizeA++;
        }
        cur = headB;
        while (cur != nullptr) {
            cur = cur->next;
            sizeB++;
        }
        int gap = 0;
        ListNode* longListHead = new ListNode();
        ListNode* shortListHead = new ListNode();
        if (sizeA > sizeB) {
            longListHead = headA;
            shortListHead = headB;
            gap = sizeA - sizeB;
        } else {
            longListHead = headB;
            shortListHead = headA;
            gap = sizeB - sizeA;
        }
        while (gap--) {
            longListHead = longListHead->next;
        }
        while (longListHead != nullptr && shortListHead != nullptr) {
            if (longListHead == shortListHead) {
                return longListHead;
            }
            longListHead = longListHead->next;
            shortListHead = shortListHead->next;
        }
        return nullptr;
    }
};


int main() {
    // 不好模拟输入数据
    return 0;
}