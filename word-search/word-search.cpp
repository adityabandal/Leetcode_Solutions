class Solution {
public:
    bool find(vector<vector<char>>& board,vector<vector<bool>>& vis,string word,int s,int i,int j){
        int m = board.size();
        int n = board[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(vis[i][j]) return false;
        
        vis[i][j] = true;
        if(board[i][j] != word[s]) {
            vis[i][j]=false;
            return false;}
        // cout<<i<<" "<<j<<"->"<<board[i][j]<<endl;
        if(s==word.size()-1) return true;
        if(find(board,vis,word,s+1,i,j+1)) return true;
        // if(find(board,vis,word,s+1,i+1,j+1)) return true;
        // if(find(board,vis,word,s+1,i-1,j+1)) return true;
        if(find(board,vis,word,s+1,i,j-1)) return true;
        // if(find(board,vis,word,s+1,i+1,j-1)) return true;
        // if(find(board,vis,word,s+1,i-1,j-1)) return true;
        if(find(board,vis,word,s+1,i+1,j)) return true;
        if(find(board,vis,word,s+1,i-1,j)) return true;
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(word.size()>m*n) return false;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(find(board,vis,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};