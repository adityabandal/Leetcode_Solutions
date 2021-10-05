class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = nums[0];
        int curr = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            curr = max(nums[i], curr+nums[i]);
            ans = max(ans, curr);
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]*=-1;
        }
        int ans1 = nums[0];
        curr = nums[0];
        for(int i=1;i<nums.size();i++){
            curr = max(nums[i], curr+nums[i]);
            ans1 = max(ans1, curr);
        }
        if(sum+ans1!=0)
        return max(ans, sum+ans1);
        else return ans;
        
    }
};