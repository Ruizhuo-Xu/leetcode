#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 以链表 dummyHead->1->2->3->4->5, k=3举例, 设pre=dummyHead, begin=1, enb=4
        // 翻转链表 1->2->3部分时,需要做两件事:
        // 1. 将翻转后的链表与之前的链表连接起来, 在这里之前的链表的最后一个节点就是dummyHead
        // 2. 将翻转后的链表与之后的链表连接起来, 在这里之后的链表的第一个节点就是end(这一步可以直接在实现链表翻转方法的时候实现,通常的写法是指向一个空指针，现在改成指向end)
        // 翻转后, 将pre = begin, begin = end,准备下一轮翻转
        ListNode* cur = head;
        int cnt = 0;
        ListNode* dummyHead = new ListNode();
        ListNode* pre = dummyHead; // 要翻转的链表的前一个节点
        dummyHead->next = head;
        ListNode* begin = head; // 要翻转的链表的第一个节点
        while (cur) {
            cnt++;
            cur = cur->next;
            if (cnt % k == 0) {
                ListNode* end = cur;  // 要翻转的链表的最后一个节点的下一个节点；需要将下一个节点存下来,因为翻转后会断开和这个节点的连接
                ListNode* newHead = reverse(begin, end);
                pre->next = newHead; // 将当前翻转后的链表和之前的部分连接起来
                pre = begin; // 翻转完后最后一个非空节点是begin，也就是下一次翻转链表的前一个节点
                begin = end; // 从cur的下一个节点开始，继续翻转
            }
        }
        return dummyHead->next;
    }

    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* pre = end; // 将要翻转的链表和之后的部分连接起来
        ListNode* cur = begin;
        while (cur != end) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};