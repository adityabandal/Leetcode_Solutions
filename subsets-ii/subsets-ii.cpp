class Solution {
public:
    void help(vector<int>& nums, int idx, vector<int>& seq, vector<vector<int>>& ans, bool skip){
        if(idx==nums.size()){
            ans.push_back(seq);
        }
        else{
            help(nums, idx+1, seq, ans, true);
            
            if(idx==0 || nums[idx-1]!=nums[idx] || !skip){
                seq.push_back(nums[idx]);
                help(nums, idx+1, seq, ans, false);
                seq.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        sort(nums.begin(), nums.end());
        help(nums, 0, seq, ans, false);
        
        return ans;
    }
};