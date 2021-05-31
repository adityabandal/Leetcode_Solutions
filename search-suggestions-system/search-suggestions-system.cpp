struct TrieNode{
    struct TrieNode* child[26];
    string endWord;
    TrieNode(){
        for(int i=0;i<26;i++) child[i] = NULL;
        endWord = "";
    }
};
class Solution {
public:
    void insert(TrieNode *root, string word){
        for(int i=0;i<word.size();i++){
            if(root->child[word[i]-'a'] == NULL){
                root->child[word[i]-'a'] = new TrieNode();
            }
            root = root->child[word[i]-'a'];
        }
        root->endWord = word;
    }
    void add(TrieNode *root, vector<string>& tmp){
        if(!root || tmp.size()==3){
            return;
        }
        if(root->endWord!="") tmp.push_back(root->endWord);
        if(tmp.size()<3)
        for(int i=0;i<26;i++){
            add(root->child[i], tmp);
        }
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode();
        
        for(string& w:products){
            insert(root, w);
        }
        
        vector<vector<string>> ans;
        int n = searchWord.size();
        
        for(int i=0;i<n;i++){
            if(root == NULL){
                ans.push_back({});
                continue;
            }
            root = root->child[searchWord[i]-'a'];
            if(root == NULL){
                ans.push_back({});
                continue;
            }
            vector<string> tmp;
            add(root, tmp);
            ans.push_back(tmp);
        }
        
        return ans;
    }
};