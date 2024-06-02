#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // 单调栈,维护一个递增的栈
        // 遍历完成后栈底元素的右侧没有比其更大的值，是题目需要保留的节点
        ListNode* dummyHead = new ListNode();
        deque<ListNode*> st; // 因为最后需要逆序栈中元素，所以使用双向队列模拟栈
        ListNode* cur = head;
        while (cur) {
            while (!st.empty() && cur->val > st.back()->val) {
                st.pop_back();
            }
            st.push_back(cur);
            cur = cur->next;
        }
        cur = dummyHead;
        while (!st.empty()) {
            cur->next = st.front();
            st.pop_front();
            cur = cur->next;
        }
        return dummyHead->next;
    }
};

int main() {
    vector<int> nums = {5, 2, 13, 3, 8};
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = Solution().removeNodes(dummyHead->next);
    cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}