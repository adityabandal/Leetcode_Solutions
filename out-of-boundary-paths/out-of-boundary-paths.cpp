#define M 1000000007
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        arr[sr][sc] = 1;
        int d[] = {0,1,0,-1,0};
        int ans= 0;
        while(maxMove--){
            vector<vector<int>> tmp(m, vector<int>(n, 0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][j]>0){
                        if(i==0) ans = (ans + arr[i][j])%M;
                        if(j==0) ans = (ans + arr[i][j])%M;
                        if(i==m-1) ans = (ans + arr[i][j])%M;
                        if(j==n-1) ans = (ans + arr[i][j])%M;
                        for(int t=0;t<4;t++){
                            int ni = i+d[t];
                            int nj = j+d[t+1];
                            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                            tmp[ni][nj] = (tmp[ni][nj]+arr[i][j])%M;
                            
                        }
                    }
                }
            }
            arr = tmp;
        }
        return ans;
    }
};