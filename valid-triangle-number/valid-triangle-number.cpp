class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                auto it = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                
                
                int x = max(0, (int)(it-nums.begin())-j-1);
                ans+=x;
            }
        }
        return ans;
    }
};