/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int p1 = p->val;
        int q1 = q->val;
        int r = root->val;
        int a = min(p1, q1);
        int b = max(p1, q1);
        if(r==a || r==b) return root;
        if(a<r && b>r) return root;
        
        else if(a<r && b<r) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};