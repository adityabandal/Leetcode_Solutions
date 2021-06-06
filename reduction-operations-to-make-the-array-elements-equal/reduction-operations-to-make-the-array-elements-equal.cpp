class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> rnk(n, 0);
        rnk[0] = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                rnk[i] = rnk[i-1]+1;
            }
            else{
                rnk[i] = rnk[i-1];
            }
            ans+=rnk[i];
        }
        return ans;
    }
};