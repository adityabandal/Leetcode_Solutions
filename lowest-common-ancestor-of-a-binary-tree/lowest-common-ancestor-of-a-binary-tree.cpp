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
    
    bool sol(TreeNode* root,TreeNode* p,vector<int>& v){
        if(!root) return 0;
        v.push_back(root->val);
        if(root->val==p->val) {
            return 1;
        }
        else if(sol(root->left,p,v) || sol(root->right,p,v)){
            return 1;
        }
        else
            v.pop_back();
            return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pv,qv;
        sol(root,p,pv);
        sol(root,q,qv);
        int x=root->val;
        int i=0;
        // for(i=0;i<pv.size();i++){
        //     cout<<pv[i]<<" ";
        // }
        // cout<<endl;
        // for(i=0;i<qv.size();i++){
        //     cout<<qv[i]<<" ";
        // }
        i=0;
        for (i = 0; i < pv.size() && i < qv.size() ; i++) 
            if (pv[i] != qv[i]) 
                break; 
        TreeNode* node = new TreeNode(pv[i-1]);
        return node;
    }
};