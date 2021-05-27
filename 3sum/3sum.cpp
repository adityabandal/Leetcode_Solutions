#define all(nums) nums.begin(), nums.end()
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(all(nums));
        if(n<=2) return {};
        int target = 0;
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            int lo = i+1;
            int hi = n-1;
            if(i>0 && nums[i] == nums[i-1]) continue;
            while(lo<hi){
                int sum = nums[i] +nums[lo]+nums[hi];
                
                if(sum == target){
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    
                    lo++;
                    hi--;
                    while(lo<n && nums[lo]==nums[lo-1]) lo++;
                }
                else if(sum>target){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        
        return ans;
    }
};