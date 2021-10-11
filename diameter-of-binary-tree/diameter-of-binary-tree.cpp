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
    int mx=0;
    int diameterOfBinaryTree1(TreeNode* root) {
        if(root==NULL) return 0;
        int l = diameterOfBinaryTree1(root->left);
        int r = diameterOfBinaryTree1(root->right);
        int a =l+r;
        if(a>mx){
            mx=a;
        }
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root){
        diameterOfBinaryTree1(root);
        return mx;
    }
};