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
    TreeNode* sol(vector<int>& preorder,int s,int l){
        cout<<s<<" "<<l<<endl;
        if(s>l) return NULL;
        if(s==l){
            TreeNode* root = new TreeNode(preorder[s]);
            // root->left=NULL;
            // root->right=NULL;
            return root;
        }
        TreeNode* root = new TreeNode(preorder[s]);
        int i;
        for(i=s+1;i<=l;i++){
            if(preorder[i]>preorder[s]) break;
        }
        if(i==l+1){
            root->left=sol(preorder,s+1,l);
            root->right=NULL;
        }
        else if(i==s+1){
            root->left=NULL;
            root->right=sol(preorder,s+1,l);
        }
        else{
            root->left=sol(preorder,s+1,i-1);
            root->right=sol(preorder,i,l);
        }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        root = sol(preorder,0,preorder.size()-1);
        return root;
    }
};