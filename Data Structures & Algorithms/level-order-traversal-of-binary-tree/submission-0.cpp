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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        // if (root->left == nullptr && root->right == nullptr) return [[root->val]];
        vector<vector<int>> left_vec = levelOrder(root->left);
        vector<vector<int>> right_vec = levelOrder(root->right);
        int d = max(left_vec.size(), right_vec.size());
        vector<vector<int>> ret = {{root->val}};
        for (int i=0; i<d; ++i) {
            if (i < left_vec.size() && i < right_vec.size()) {
                left_vec[i].insert(left_vec[i].end(), right_vec[i].begin(), right_vec[i].end());
                ret.push_back(left_vec[i]);
            } else if (i < left_vec.size()) {
                ret.push_back(left_vec[i]);
            } else if (i < right_vec.size()) {
                ret.push_back(right_vec[i]);
            }
        }
        return ret;
    }
};
