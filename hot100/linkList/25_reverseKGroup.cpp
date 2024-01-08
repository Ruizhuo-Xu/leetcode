#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 维护三个变量pre, start, end；
        // pre记录当前要翻转的链表的前一个结点
        // start记录当前要翻转的链表的第一个结点
        // end记录的是当前要翻转的链表最后一个结点的下一个结点
        // 翻转前: pre->start->...->tail->end
        // 翻转后: pre->tail->...->start->end
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* start = head;
        ListNode* end = nullptr;
        while (true) {
            ListNode* cur = start;
            for (int i = 0; i < k; i++) {
                if (cur == nullptr) {
                    return dummyHead->next;
                }
                cur = cur->next;
            }
            end = cur;
            pre->next = reverseList(start, end); // 将当前翻转的链表之前的节点指向翻转后的链表
            pre = start; // 翻转后start节点变成末尾节点,也即是下一轮翻转链表的前一个结点
            start = end; // 下一轮翻转的链表是当前要翻转链表的下一个结点
        }
        return nullptr;
    }

    ListNode* reverseList(ListNode* start, ListNode* end) {
        // 翻转[start, end)之间的链表,end是要翻转的链表的下一个节点
        // 翻转后,原链表的起始位置(start)指向end
        ListNode* pre = end;
        ListNode* cur = start;
        while (cur != end) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};


int main () {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = Solution().reverseKGroup(dummyHead->next, 2);
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}