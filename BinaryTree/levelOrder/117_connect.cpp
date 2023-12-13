#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* preNode;
            Node* curNode;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    preNode = que.front();
                    que.pop();
                    curNode = preNode;
                } else {
                    curNode = que.front();
                    que.pop();
                    preNode->next = curNode;
                    preNode = preNode->next;
                }
                if (curNode->left != nullptr) que.push(curNode->left);
                if (curNode->right != nullptr) que.push(curNode->right);
            }
        }
        return root;
    }
};