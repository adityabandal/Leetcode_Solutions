class Solution {
public:
    int help(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j< 0 || i>=n || j>=m || grid[i][j]!=1) return 0;
        
        grid[i][j] = -1;
        int ans = 1;
        int d[] = {1,0,-1,0,1};
        for(int t=0;t<4;t++){
            ans += help(grid, i+d[t], j+d[t+1]);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    ans = max(ans, help(grid, i, j));
            }
        }
        
        return ans;
    }
};