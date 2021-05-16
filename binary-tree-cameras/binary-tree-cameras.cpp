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
    unordered_set<TreeNode *> m;
    int ans;
    
    void help(TreeNode *root, TreeNode *p){
        if(root){
            help(root->left, root);
            help(root->right, root);
            
            if(p==NULL && !m.count(root)||!m.count(root->left)||!m.count(root->right)){
                ans++;
                m.insert(root);
                m.insert(root->left);
                m.insert(root->right);
                m.insert(p);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;
        m.insert(NULL);
        help(root, NULL);
        return ans;
    }
};