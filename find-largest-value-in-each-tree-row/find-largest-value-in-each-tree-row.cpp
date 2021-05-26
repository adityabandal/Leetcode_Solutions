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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        queue<TreeNode *> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            int mx = q.front()->val;
            int n = q.size();
            
            for(int i=0;i<n;i++){
                mx = max(mx, q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                // cout<<q.front()->val<<endl;
                q.pop();
            }
            ans.push_back(mx);
        }
        
        return ans;
    }
};