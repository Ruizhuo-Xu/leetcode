#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* func(ListNode* head) {
    vector<ListNode*> list;
    ListNode* cur = head;
    while (cur) {
        list.push_back(cur);
        cur = cur->next;
    }
    stack<int> st;
    vector<int> rec(list.size(), -1);
    for (int i = 0; i < list.size(); i++) {
        while (!st.empty() && list[i]->val > list[st.top()]->val) {
            rec[st.top()] = i; // 右侧第一个大于的元素下标
            st.pop();
        }
        st.push(i);
    }
    ListNode* dummyHead = new ListNode(0);
    cur = dummyHead;
    for (int i = 0; i < rec.size(); i++) {
        if (rec[i] == -1) {
            cur->next = list[i];
            cur = cur->next;
        }
    }
    return dummyHead->next;
}

int main() {
    vector<int> nums = {5, 2, 13, 3, 8};
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = func(dummyHead->next);
    cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}