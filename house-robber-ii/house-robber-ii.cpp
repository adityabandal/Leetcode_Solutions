class Solution {
public:
    int _rob(vector<int>& nums, int lo, int hi){
        int pprev = 0;
        int prev = nums[lo];
        
        for(int i=lo+1;i<=hi;i++){
            int curr = max(prev, pprev+nums[i]);
            pprev = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(_rob(nums, 0, n-2), _rob(nums, 1, n-1));
    }
};