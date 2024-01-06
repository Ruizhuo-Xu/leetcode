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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = list2;
        ListNode* cur1 = list1;
        ListNode* cur2 = dummyHead;
        while (cur1) {
            while (cur2->next != nullptr && cur2->next->val < cur1->val) { // 找到插入的位置
                cur2 = cur2->next;
            }
            ListNode* temp = cur1->next;
            cur1->next = cur2->next;
            cur2->next = cur1;
            cur1 = temp;
        }
        return dummyHead->next; // 返回虚拟头节点的下一个结点,因为插入可能list2不再是头节点
    }
};

int main() {
    vector<int> nums1 = {1, 2, 4};
    ListNode* dummyHead1 = new ListNode();
    ListNode* cur = dummyHead1;
    for (int num : nums1) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    vector<int> nums2 = {1, 3, 4};
    ListNode* dummyHead2 = new ListNode();
    cur = dummyHead2;
    for (int num : nums2) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = Solution().mergeTwoLists(dummyHead1->next, dummyHead2->next);
    cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}