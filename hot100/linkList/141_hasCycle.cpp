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
    bool hasCycle(ListNode *head) {
        // 快慢指针,时间复杂度O(n),空间复杂度O(1)
        if (head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {3,2,0,-4};
    int pos = 1;
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* start = dummyHead->next;
    if (pos >= 0) {
        while (pos--) {
            start = start->next;
        }
        cur->next = start;
    }
    cout << Solution().hasCycle(dummyHead->next) << endl;
    return 0;
}