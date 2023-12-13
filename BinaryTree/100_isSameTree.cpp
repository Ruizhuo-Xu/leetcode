#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
    
    bool compare(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q != nullptr) return false;
        else if (p != nullptr && q == nullptr) return false;
        else if (p == nullptr && q == nullptr) return true;
        else if (p->val != q->val) return false;
        return compare(p->left, q->left) && compare(p->right, q->right);
    }
};

int main() {

}