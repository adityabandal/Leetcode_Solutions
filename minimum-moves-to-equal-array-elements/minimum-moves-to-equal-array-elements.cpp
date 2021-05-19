class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mn = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            mn = min(mn, nums[i]);
            sum+=nums[i];
        }
        
        return sum - mn*nums.size();
    }
};