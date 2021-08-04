/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        else return to_string(root->val)+','+serialize(root->left)+','+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deser(string& data){
        if(data[0]=='#'){
            if(data.size()>1) data = data.substr(2);
            return NULL;
        }
        else{
            int pos = data.find(',');
            string tmp = data.substr(0, pos+1);
            data = data.substr(pos+1);
            int val = stoi(tmp);
            TreeNode* root = new TreeNode(val);
            root->left = deser(data);
            root->right = deser(data);
            return root;
        }
    }
    TreeNode* deserialize(string data) {
        // cout<<data<<endl;
        return deser(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));