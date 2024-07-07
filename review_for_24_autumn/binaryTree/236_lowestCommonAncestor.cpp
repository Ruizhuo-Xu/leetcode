#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // 寻找树中最近公共祖先
        if (root == p || root == q || root == nullptr) { 
            // 如果当前树的根节点包含某个目标节点,则是候选的公共祖先,直接返回,不需要继续遍历了,因为这个时候只有两种情况:
            // 1.另一个候选节点也在当前的树中,那么此时的节点就是最近公共祖先,无需后续遍历；2.另一个候选节点在另外的子树中，那么后续节点也无需遍历了
            // 如果当前树的根节点为空,说明当前树为空,不可能是公共祖先，返回null
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); // 寻找左子树中最近公共祖先
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // 寻找右子树中最近公共祖先
        if (left == nullptr && right != nullptr) { // 如果左子树中不包含目标节点,但右子树包含,则所有目标节点都在右子树中,返回右子树候选节点作为公共祖先
            return right;
        } else if (left != nullptr && right == nullptr) { // 同理
            return left;
        } else if (left == nullptr && right == nullptr) { // 如果左右子树都不包含目标节点,则当前根节点的树不是公共祖先
            return nullptr;
        } else { // 如果左右子树分别包含一个目标节点,则当前节点是最近公共祖先
            return root;
        }
    }
};