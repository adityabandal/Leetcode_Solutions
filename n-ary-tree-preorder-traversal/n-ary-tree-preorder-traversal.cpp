/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node *> s;
        vector<int> ans;
        if(root==NULL) return ans;
        s.push(root);
        
        while(!s.empty()){
            Node *tmp = s.top();
            s.pop();
            ans.push_back(tmp->val);
            for(int i=tmp->children.size()-1;i>=0;i--){
                if(tmp->children[i]){
                    s.push(tmp->children[i]);
                }
            }
        }
         return ans;
    }
};