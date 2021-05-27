class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int c = target - nums[i];
            if(m.find(c)!=m.end()){
                return {m[c]+1, i+1};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};