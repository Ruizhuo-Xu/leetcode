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
    bool isPalindrome(ListNode* head) {
        // 时间复杂度O(n),空间复杂度O(1)
        if (head == nullptr) return true;
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* reversedHalfHead = reverseList(firstHalfEnd->next); // 翻转后半部分
        ListNode* p1 = head;
        ListNode* p2 = reversedHalfHead;
        bool res = true;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                res = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // 还原链表
        firstHalfEnd->next = reverseList(reversedHalfHead);
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        // 快慢指针,快指针一次走两步,慢指针一次走一步
        // 快指针到结尾时,慢指针正好到一半的位置
        // 当链表长度为奇数时,链表中间的元素划归前半部分
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 1};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cout << Solution().isPalindrome(dummyHead->next) << endl;
    return 0;
}