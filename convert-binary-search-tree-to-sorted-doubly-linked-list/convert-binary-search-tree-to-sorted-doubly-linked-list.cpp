/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node * prev;
    void inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        prev->right = root;
        root->left = prev;
        prev = root;
        inorder(root->right);
        
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        prev = new Node(0);
        Node *ans = prev;
        inorder(root);
        ans = ans->right;
        ans->left = prev;
        prev->right = ans;
        return ans;
    }
};