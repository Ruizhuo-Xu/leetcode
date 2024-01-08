#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists_(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* dummyHead  = new ListNode();
        dummyHead->next = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ListNode* p1 = dummyHead;
            ListNode* p2 = lists[i];
            while (p2 != nullptr) {
                while (p1->next != nullptr && p1->next->val < p2->val) {
                    p1 = p1->next;
                }
                ListNode* temp = p1->next;
                p1->next = p2;
                p2 = p2->next;
                p1->next->next = temp;
            }
        }
        return dummyHead->next;
    }

    struct cmp {
        bool operator () (ListNode* p1, ListNode* p2) { // 通过重写仿函数来支持自定义数据类型,仿函数是通过重载“()”运算符来模拟函数操作的类。
            return p1->val > p2->val; // 小顶堆
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) que.push(lists[i]);
        }
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        while (!que.empty()) {
            cur->next = que.top();
            que.pop();
            cur = cur->next;
            if (cur->next != nullptr) que.push(cur->next);
        }
        return dummyHead->next;
    }
};

int main() {
    // vector<int> nums = [[1,4,5],[1,3,4],[2,6]];
}