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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummyHead = new ListNode();
        ListNode* p3 = dummyHead;
        int temp = 0;
        while (p1 != nullptr || p2 != nullptr) {
            int sum = 0;
            if (p1 != nullptr && p2 != nullptr) {
                sum = p1->val + p2->val + temp;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1 == nullptr) {
                sum = p2->val + temp;
                p2 = p2->next;
            } else {
                sum = p1->val + temp;
                p1 = p1->next;
            }
            temp = sum / 10; // 表示进位
            p3->next = new ListNode(sum % 10);
            p3 = p3->next;
        }
        if (temp == 1) { // 如果还有进位,则创建一个新的节点
            p3->next = new ListNode(1);
        }
        return dummyHead->next;
    }
};

int main() {
    vector<int> l1 = {2,4,3};
    vector<int> l2 = {5,6,4};
    ListNode* dummyHead1 = new ListNode();
    ListNode* dummyHead2 = new ListNode();
    ListNode* cur = dummyHead1;
    for (int num : l1) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = dummyHead2;
    for (int num : l2) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = Solution().addTwoNumbers(dummyHead1->next, dummyHead2->next);
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}