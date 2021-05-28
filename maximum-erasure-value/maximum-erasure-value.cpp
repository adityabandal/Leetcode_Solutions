class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        int cs[n+1];
        cs[0] = 0; // i-j c[j+1]-cs[i]
        
        
        
        int ans = 0;
        int left = 0;
        for(int i=0;i<n;i++){
            cs[i+1] = cs[i]+nums[i];
            if(m.find(nums[i])!=m.end()){
                left = max(left, m[nums[i]]+1);
            }
            
            ans = max(ans, cs[i+1]-cs[left]);
            
            m[nums[i]] = i;
        }
        
        return ans;
    }
};