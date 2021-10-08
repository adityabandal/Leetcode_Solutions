typedef struct _trienode{
    struct _trienode* children[26];
    bool isEnd;
    bool suf;
} trieNode;
class Trie {
public:
    /** Initialize your data structure here. */
    trieNode* root;
    Trie() {
        root = new trieNode;
        root->isEnd=false;
        root->suf=false;
        for(int i=0;i<26;i++){
            root->children[i]=NULL;
        }
    }
    
    trieNode* getNode(){
        trieNode* node = new trieNode;
        node->isEnd=false;
        node->suf=false;
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        return node;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(ptr->children[word[i]-'a']==NULL){
                ptr->children[word[i]-'a']=getNode();
            }
            ptr->suf=true;
            ptr=ptr->children[word[i]-'a'];
        }
        ptr->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(ptr->children[word[i]-'a']==NULL)
                return false;
            ptr=ptr->children[word[i]-'a'];
        }
        return (ptr!=NULL &&  ptr->isEnd);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode* ptr=root;
        for(int i=0;i<prefix.size();i++){
            if(ptr->children[prefix[i]-'a']==NULL)
                return false;
            ptr=ptr->children[prefix[i]-'a'];
        }
        return (ptr!=NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */