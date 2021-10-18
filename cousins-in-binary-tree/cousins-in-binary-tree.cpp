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
    
    void dept(TreeNode* root, int* dep, int* par, int x, int d){
        if(root==NULL) return;
        else{
            // dep=69;
            // cout<<root->val;
            if(root->left!=NULL){
                // cout<<"l ";
                if(root->left->val==x){
                    *dep=d+1;
                    *par=root->val;
                }
            }
            if(root->right!=NULL){
                // cout<<"r ";
                if(root->right->val==x){
                    *dep=d+1;
                    *par=root->val;
                }
            }
            // cout<<"end"<<endl;
            dept(root->left,dep,par,x,d+1);
            dept(root->right,dep,par,x,d+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1,d2,p1,p2;
        dept(root,&d1,&p1,x,0);
        dept(root,&d2,&p2,y,0);
        if(d1==d2 && p1!=p2){
            return true;
        }
        // cout<<d1<<" "<<p1<<" "<<d2<<" "<<p2;
        return 0;
    }
};