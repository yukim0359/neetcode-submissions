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

class Codec {
public:
    void dfsSerialize(TreeNode* node, string& s) {
        if (node == nullptr) {
            s += "N,";
            return;
        }

        s += to_string(node->val) + ",";
        dfsSerialize(node->left, s);
        dfsSerialize(node->right, s);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& i) {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;

        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfsSerialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string cur;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        int i = 0;
        return dfsDeserialize(vals, i);
    }
};
