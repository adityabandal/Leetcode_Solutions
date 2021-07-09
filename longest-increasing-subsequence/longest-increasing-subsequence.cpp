class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        
        vector<int> ans;
        int len=0;
        
        for(int i=0;i<n;i++){
            auto it = lower_bound(ans.begin(),ans.end(),arr[i]);
            if(it == ans.end()){
                ans.push_back(arr[i]);
                len++;
            }
            else{
                int ind = it - ans.begin();
                ans[ind] = arr[i];
            }
        }
        // for(int x:ans){
        //     cout<<x<<" ";
        // }
        return len;
    }
};