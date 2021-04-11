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
    int mx;
    int sum;
    void help(TreeNode* root, int h){
        if(!root) return;
        if(h>mx){
            mx = h;
            sum = root->val;
        }
        else if(h == mx){
            sum+=root->val;
        }
        help(root->left, h+1);
        help(root->right, h+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        mx = INT_MIN;
        sum = 0;
        help(root, 0);
        return sum;
    }
};