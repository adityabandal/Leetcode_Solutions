struct trie{
    struct trie* child[26];
    string word;
    
    trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        word="";
    }
};
class Solution {
public:
    trie* buildTrie(vector<string>& words){
        trie *root = new trie();
        for(string w:words){
            trie *r = root;
            for(char c:w){
                if(r->child[c-'a']==NULL){
                    r->child[c-'a'] = new trie();
                }
                r = r->child[c-'a'];
            }
            r->word = w;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, trie *root, vector<string>& words){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())  return;
        
        char c = board[i][j];
        
        if(c=='*' || root->child[c-'a']==NULL) return;
        
        root = root->child[c-'a'];
        if(root->word!=""){
            words.push_back(root->word);
            root->word = "";
        }
        
        board[i][j] = '*';
        dfs(board,i+1,j,root,words);
        dfs(board,i-1,j,root,words);
        dfs(board,i,j+1,root,words);
        dfs(board,i,j-1,root,words);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        trie *root = buildTrie(words);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,root,ans);
            }
        }
        return ans;
    }
};