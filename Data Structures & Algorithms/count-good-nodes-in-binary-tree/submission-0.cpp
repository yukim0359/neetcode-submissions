/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans;

    void dfs(TreeNode* node, int maxVal) {
        if (!node) return;
        if (maxVal <= node->val) {
            maxVal = node->val;
            ans++;
        }
        dfs(node->left, maxVal);
        dfs(node->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root, -INT_MAX);
        return ans;
    }
};
