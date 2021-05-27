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
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> m;
        stack<TreeNode *> st;
        while(root1 || !st.empty()){
            while(root1){
                st.push(root1);
                root1 = root1->left;
            }
            m.insert(target-st.top()->val);
            root1 = st.top()->right;
            // cout<<st.top()->val<<endl;
            st.pop();
        }
        
        while(root2 || !st.empty()){
            while(root2){
                st.push(root2);
                root2 = root2->left;
            }
            // m.insert(target-st.top()->val);
            if(m.find(st.top()->val)!=m.end()) return true;
            root2 = st.top()->right;
            // cout<<st.top()->val<<endl;
            st.pop();
        }
        
        return false;
    }
};