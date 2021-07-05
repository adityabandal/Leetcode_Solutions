class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(r*c!=n*m) return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int x = 0, y = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // cout<<i<<" "<<j<<"-"<<x<<" "<<y<<endl;
                ans[i][j] = mat[x][y];
                y++;
                if(y==m){
                    y=0;
                    x++;
                }
            }
        }
        
        return ans;
    }
};