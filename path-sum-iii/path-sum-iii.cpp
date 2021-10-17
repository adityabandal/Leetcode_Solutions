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
    int ans;
    vector<int> sumtree(TreeNode *root,int sum){
        if(root==NULL) return {};
        if(!root->left && !root->right) {
            if(root->val==sum) ans++;
            return {root->val};
        }
        else{
            vector<int> l = sumtree(root->left,sum);
            vector<int> r = sumtree(root->right,sum);
            vector<int> ret;
            ret.push_back(root->val);
            if(root->val==sum){
                ans++;
            }
            for(int x:l){
                ret.push_back(x+root->val);
                if(x+root->val==sum) ans++;
            }
            for(int x:r){
                ret.push_back(x+root->val);
                if(x+root->val==sum) ans++;
            }
            return ret;
        }
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        sumtree(root,sum);
        return ans;
    }
};