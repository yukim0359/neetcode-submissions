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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;
        if (root) q.push({root, 1});

        while (!q.empty()) {
            auto [cur, depth] = q.front();
            q.pop();
            if (cur->left) q.push({cur->left, depth + 1});
            if (cur->right) q.push({cur->right, depth + 1});
            if (ans.size() != 0 && depth == ans.size()) {
                ans.pop_back();
            }
            ans.push_back(cur->val);
        }

        return ans;
    }
};
