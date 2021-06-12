#define pi pair<int, int>
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int d[] = {0,1,0,-1,0};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pi> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int itr = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(vis[x][y]) continue;
                vis[x][y] = true;
                mat[x][y] = itr;
                for(int j=0;j<4;j++){
                    int nx = x+d[j], ny = y+d[j+1];
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    q.push({nx, ny});
                }
            }
            itr++;
        }
        return mat;
    }
};