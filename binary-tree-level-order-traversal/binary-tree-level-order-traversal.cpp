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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> tmp;
            
            for(int i=0;i<s;i++){
                TreeNode* ptr = q.front();
                q.pop();
                
                tmp.push_back(ptr->val);
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};