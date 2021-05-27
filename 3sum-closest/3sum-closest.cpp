class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            
            for(int sum:s){
                if(abs(target-nums[i]-sum)<abs(target-ans)){
                    ans = nums[i]+sum;
                }
            }
            
            for(int j=0;j<i;j++){
                s.insert(nums[i]+nums[j]);
            }
            
        }
        return ans;
    }
};