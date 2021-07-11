class Solution {
public:
    int help(vector<vector<char>>& maze, int x, int y){
        
        int n = maze.size();
        int m = maze[0].size();
        if(maze[x][y]!='.') return INT_MAX;
        if(x==0 || x==n-1 || y==0 || y==m-1) return 0;
        // cout<<x<<" "<<y<<endl;
        maze[x][y] = '*';
        int d[] = {0,1,0,-1,0};
        int ans = INT_MAX;
        for(int t=0;t<4;t++){
            int r = help(maze, x+d[t], y+d[t+1]);
            if(r!=INT_MAX)
                ans = min(ans, r+1);
        }
        return ans;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();
        int ans = INT_MAX;
        int d[] = {0,1,0,-1,0};
        int x = e[0], y = e[1];
        maze[x][y] = '*';
        queue<pair<int, int>> q;
        for(int t=0;t<4;t++){
            int nx = x+d[t];
            int ny = y+d[t+1];
            if(nx<0 || nx>=n || ny<0 || ny>=m || maze[nx][ny]!='.') continue;
            q.push({nx, ny});
        }
        int dist = 1;
        while(!q.empty()){
            int s = q.size();
            for(int k=0;k<s;k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(maze[i][j]!='.') continue;
                if(i==0 || i==n-1 || j==0 || j==m-1) return dist;
                maze[i][j] = '*';
                for(int t=0;t<4;t++){
                    int nx = i+d[t];
                    int ny = j+d[t+1];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || maze[nx][ny]!='.') continue;
                    q.push({nx, ny});
                }
            }
            dist++;
        }
        
        return -1;
    }
};