#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};


class Solution {
public:
    struct cmp {
        bool operator () (ListNode* p1, ListNode* p2) {
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                heap.push(lists[i]);
            }
        }
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        while (!heap.empty()) {
            cur->next = heap.top();
            heap.pop();
            cur = cur->next;
            if (cur->next != nullptr) {
                heap.push(cur->next);
            }
        }
        return dummyHead->next;
    }
};