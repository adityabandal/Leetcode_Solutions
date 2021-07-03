class Solution {
public:
    int help(vector<int>& arr, int k){
        int csum = 0;
        set<int> s;
        s.insert(csum);
        int ans = INT_MIN;
        for(int i=0;i<arr.size();i++){
            csum+=arr[i];
            // cout<<csum<<" ";
            auto it = s.lower_bound(csum-k);
            if(it!=s.end()){
                ans = max(ans, csum-(*it));
            }
            
            s.insert(csum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> arr(m, 0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    arr[k]+=mat[j][k];
                }
                // cout<<i<<" "<<j<<endl;
                int x = help(arr, k);
                // cout<<endl;
                ans = max(ans, x);
            }
        }
        return ans;
    }
};