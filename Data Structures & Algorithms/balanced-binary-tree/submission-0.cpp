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
    bool ans = true;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        if (leftDepth > rightDepth + 1 || rightDepth > leftDepth + 1) {
            ans = false;
        }
        return max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
