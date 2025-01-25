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
    void _postorderTraversal(TreeNode* root) {
        if(!root)
            return;
        _postorderTraversal(root->left);
        _postorderTraversal(root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        _postorderTraversal(root);
        return result;
    }
};