#define pi pair<int, int>
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<n;i++){
            dp[i] = nums[i] + dp[q.front()];
            // cout<<i<<"-> "<<q.front()<<" "<<dp[q.front()]<<"=> "<<dp[i]<<endl;
            while(!q.empty() && dp[i]>dp[q.back()]) {
                // cout<<"pop "<<q.back()<<endl;
                q.pop_back();}
            while(!q.empty() && q.front() < i+1-k){ 
                // cout<<"pop "<<q.front()<<endl;
                q.pop_front();}
            
            q.push_back(i);
        }
        return dp[n-1];
    }
};