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
    TreeNode* sol(vector<int>& nums,int lo,int hi){
        if(lo > hi) return NULL;
        else{
            cout<<lo<<" "<<hi<<endl;
            int mid = (lo+hi)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = sol(nums,lo,mid-1);
            root->right = sol(nums,mid+1,hi);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *ans = sol(nums,0,nums.size()-1);
        return ans;
    }
};