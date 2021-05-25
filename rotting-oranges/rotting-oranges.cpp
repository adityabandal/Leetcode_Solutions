class Solution {
public:
    int ans;
    
    int dfs(vector<vector<int>>& grid, int time, int g){
        if(g == 0) return time;
        int n = grid.size();
        int m = grid[0].size();
        int ig = g;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    // grid[i][j] = 3;
                    if(i-1>=0 && grid[i-1][j]==1){
                        grid[i-1][j] = 3;
                        g--;
                    }
                    if(j-1>=0 && grid[i][j-1]==1){
                        grid[i][j-1] = 3;
                        g--;
                    }
                    if(i+1<n && grid[i+1][j]==1){
                        grid[i+1][j] = 3;
                        g--;
                    }
                    if(j+1<m && grid[i][j+1]==1){
                        grid[i][j+1] = 3;
                        g--;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 3){
                    grid[i][j] = 2;
                }        
            }
        }
        if(g == ig) return -1;
        else return dfs(grid, time+1, g);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int rotten = 0;
        int good = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    good++;
                }
            }
        }
        return dfs(grid, 0, good);
    }
};