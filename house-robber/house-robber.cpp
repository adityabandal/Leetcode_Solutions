class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int f = nums[0];
        int s = max(f, nums[1]);
        
        for(int i=2;i<n;i++){
            int tmp = max(nums[i]+f, s);
            f = s;
            s = tmp;
        }
        return s;
    }
};