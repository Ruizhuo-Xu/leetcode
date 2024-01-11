#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(vector<string> data) {
    if (data.size() == 0) return nullptr;
    vector<TreeNode*> tree(data.size(), nullptr);
    for (int i = 0; i < data.size(); i++) {
        if (data[i] != "null") {
            tree[i] = new TreeNode(stoi(data[i]));
        }
    }
    for (int i = 0; i * 2 + 1 < tree.size(); i++) {
        if (tree[i] != nullptr)  {
            tree[i]->left = tree[i * 2 + 1];
            if (i * 2 + 2 < tree.size()) {
                tree[i]->right = tree[i * 2 + 2];
            }
        }
    }
    return tree[0];
}

class Solution {
public:
    int res = 0;
    unordered_map<long, int> mp; // 前缀和：出现次数
    int pathSum(TreeNode* root, int targetSum) {
        // 方法类似560_subarraySum
        mp[0] = 1; // 前缀和初始化条件,还没累加任何元素
        traversal(root, targetSum, 0);
        return res;
    }

    void traversal(TreeNode* root, int targetSum, long sum) {
        if (root == nullptr) return ;
        sum += root->val;
        // cout << "sum: " << sum << " sum-target: "  << sum - targetSum << endl;
        if (mp.find(sum - targetSum) != mp.end()) {
            res += mp[sum - targetSum];
        }
        mp[sum]++;
        traversal(root->left, targetSum, sum);
        traversal(root->right, targetSum, sum);
        mp[sum]--;
    }
};

int main() {
    // vector<string> data = {"10","5","-3","3","2","null","11","3","-2","null","1"};
    vector<string> data = {"5","4","8","11","null","13","4","7","2","null","null","5","1"};
    TreeNode* root = constructTree(data);
    int targetSum = 22;
    cout << Solution().pathSum(root, targetSum) << endl;
    return 0;
}