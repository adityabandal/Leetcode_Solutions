class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            unordered_set<int> s;
            for(int j=i+1;j<n;j++){
                // if(j!=i+1 && nums[j] == nums[j-1]) continue;
                if(s.find(target-nums[j])!=s.end()){
                    ans.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                    while(j+1<n && nums[j+1]==nums[j]) j++;
                    
                }
                s.insert(nums[j]);
            }
        }
        return ans;
    }
};