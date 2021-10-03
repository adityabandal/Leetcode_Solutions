class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // int curr = nums[0];
        int mx = nums[0];
        
        for(int i=0;i<n;i++){
            if(mx < i){
                return false;
            }
            else{
                mx = max(mx, i+nums[i]);
            }
        }
        return true;
    }
};