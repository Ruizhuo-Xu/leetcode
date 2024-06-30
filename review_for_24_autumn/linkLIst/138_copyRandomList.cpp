#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> mp;
        vector<Node*> rec;
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr) {
            Node* temp = new Node(cur->val);
            rec.push_back(temp);
            mp[cur] = idx++;
            cur = cur->next;
        }
        rec.push_back(nullptr);
        mp[nullptr] = idx;
        cur = head;
        idx = 0;
        while (cur != nullptr) {
            rec[idx]->next = rec[idx + 1];
            rec[idx]->random = rec[mp[cur->random]];
            cur = cur->next;
            idx++;
        }
        return rec[0];
    }
};