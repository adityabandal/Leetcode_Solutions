class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
        vector<vector<int>> left(n, vector<int>(n,0)), right(n, vector<int>(n,0)), up(n, vector<int>(n,0)), down(n, vector<int>(n,0)), mines(n, vector<int>(n,1));
        
        
        for(auto m:mine){
            mines[m[0]][m[1]] = 0;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<mines[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mines[i][j]){
                    left[i][j] = (j==0)?1:left[i][j-1]+1;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(mines[i][j]){
                    right[i][j] = (j==n-1)?1:right[i][j+1]+1;
                }
            }
        }
        
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(mines[i][j]){
                    up[i][j] = (i==0)?1:up[i-1][j]+1;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(mines[i][j]){
                    down[i][j] = (i==n-1)?1:down[i+1][j]+1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<up[i][j]<<" ";
                ans = max(ans, min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])));
            }
            // cout<<endl;
        }
        
        return ans;
    }
};