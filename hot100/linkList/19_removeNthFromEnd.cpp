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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* left = dummyHead;
        ListNode* right = dummyHead;
        while (n--) {
            right = right->next;
        }
        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = Solution().removeNthFromEnd(dummyHead->next, n);
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}