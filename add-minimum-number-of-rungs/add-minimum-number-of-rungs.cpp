class Solution {
public:
    int addRungs(vector<int>& nums, int dist) {
        int ans = 0;
        if(nums[0] > dist){
            ans += (nums[0]-dist-1)/dist + 1;
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>dist){
                ans += (nums[i]-nums[i-1]-dist-1)/dist +1;
            }
        }
        return ans;
    }
};