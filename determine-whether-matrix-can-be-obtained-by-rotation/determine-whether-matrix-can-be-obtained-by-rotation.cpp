class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(mat[i][j], mat[i][n-1-j]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        for(int i=0;i<3;i++){
            rotate(mat);
            if(mat==target) return true;
        }
        return false;
    }
};