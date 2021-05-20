class Solution {
public:
    int mn;
    vector<vector<int>> dp;
    int help(vector<int>& nums, int idx, int target){
        if(idx > nums.size() || target-mn >= dp.size()) return 0;
        // cout<<target-mn<<" "<<idx<<endl;
        if(dp[target-mn][idx]!=-1) return dp[target-mn][idx];
        else if(idx == nums.size()){
            if(target==0) return dp[target-mn][idx]=1;
            else return dp[target-mn][idx]=0;
        }
        else{
            return dp[target-mn][idx]=help(nums, idx+1, target+nums[idx])+help(nums, idx+1, target-nums[idx]);
        }
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        mn = -sum;
        // cout<<sum-mn+1<<endl;
        dp = vector<vector<int>>(sum-mn+1, vector<int>(nums.size()+1, -1));
        return help(nums, 0, target);
    }
};