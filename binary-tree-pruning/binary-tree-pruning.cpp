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
    bool dfs(TreeNode *root){
        if(!root) return false;
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if(!l) root->left = NULL;
        if(!r) root->right = NULL;
        
        return (root->val == 1) || r || l;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root)) return root;
        return NULL;
    }
};