class Solution {
public:
    vector<int> nxt;
    vector<int> dp;
    int help(const vector<vector<int>>& arr, int idx){
        if(idx == arr.size() || idx==-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        else{
            int skip = help(arr, idx+1);
            int incl = help(arr, nxt[idx])+arr[idx][2];
            // cout<<idx<<"->"<<skip<<" "<<incl<<endl;
            return dp[idx] = max(skip, incl);
        }
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int>next;
        int n = profit.size();
        nxt = vector<int>(n, -1);
        dp = vector<int>(n, -1);
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-1;i++){
            int lo = i+1, hi = n-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(arr[mid][0]>=arr[i][1]){
                    nxt[i] = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<arr[i][2]<<"-"<<nxt[i]<<" ";
        // }
        // cout<<endl;
        return help(arr, 0);
    }
};