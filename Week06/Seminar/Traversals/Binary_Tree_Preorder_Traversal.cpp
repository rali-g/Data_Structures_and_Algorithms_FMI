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
    vector<int> result;
    void _preorderTraversal(TreeNode* root)
    {
        if(!root)
            return;
        result.push_back(root->val);
        _preorderTraversal(root->left);
        _preorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        _preorderTraversal(root);
        return result;
    }
};