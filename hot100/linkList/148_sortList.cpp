#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) { // 节点数量可能为0
            return head;
        }
        return mergeSort(head, nullptr);
    }

    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        // 链表归并排序, 左闭右开
        if (head->next == tail) { // 只有一个节点
            head->next = nullptr; // 将head和后续节点断开,因为后面要合并
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail) { // 利用快慢指针找到中间节点
            // fast到达尾部节点tail时，slow刚好到达中间节点
            fast = fast->next;
            slow = slow->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        ListNode* head1 = mergeSort(head, mid);
        ListNode* head2 = mergeSort(mid, tail);
        return merge(head1, head2);
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        // 合并两个有序链表
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* p3 = dummyHead;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p3->next = p1;
                p1 = p1->next;
            } else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if (p1 == nullptr) {
            p3->next = p2;
        } else if (p2 == nullptr) {
            p3->next = p1;
        }
        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {4, 2, 1, 3};
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = Solution().sortList(dummyHead->next);
    cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}

