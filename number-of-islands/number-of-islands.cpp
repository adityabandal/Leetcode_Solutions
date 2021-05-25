class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j] = '0';
        
        int d[] = {1,0,-1,0,1};
        
        for(int t=0;t<4;t++){
            dfs(grid, i+d[t], j+d[t+1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};