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
    // vector<int> ans;
    void leaf(TreeNode *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    void left(TreeNode *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        ans.push_back(root->val);
        if(root->left){
            left(root->left, ans);
        }
        else{
            left(root->right, ans);
        }
    }
    void right(TreeNode *root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        ans.push_back(root->val);
        if(root->right){
            right(root->right, ans);
        }
        else{
            right(root->left, ans);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // int h = height(root);
        if(!root) return {};
        // ans.push_back(root->val);
        vector<int> lv;
        left(root->left, lv);
        
        vector<int> rv;
        right(root->right, rv);
        
        vector<int> rtv;
        leaf(root->left, rtv);
        leaf(root->right, rtv);
        
        
        vector<int> ans;
        ans.push_back(root->val);
        
        for(int x:lv) ans.push_back(x);
        for(int x:rtv) ans.push_back(x);
        for(int i=rv.size()-1;i>=0;i--){
            ans.push_back(rv[i]);
        }
        return ans;
    }
};