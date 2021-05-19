class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int idx = n/2;
        int ans = 0;
        for(int a:nums){
            ans += abs(a-nums[idx]);
        }
        return ans;
    }
};