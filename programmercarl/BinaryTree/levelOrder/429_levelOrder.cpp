#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            while (size--) {
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i] != nullptr) que.push(node->children[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->children = vector<Node*>({new Node(3), new Node(2), new Node(4)});
    root->children[0]->children = vector<Node*>({new Node(5), new Node(6)});
    vector<vector<int>> res = Solution().levelOrder(root);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}