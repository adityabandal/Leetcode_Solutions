class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int mx = INT_MIN;
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                cnt++;
                if(i==1 || nums[i-2]<=nums[i]) nums[i-1]=nums[i];
                else nums[i]=nums[i-1];
            }
            
            if(cnt>1) return false;
        }
        return cnt<=1;
    }
};