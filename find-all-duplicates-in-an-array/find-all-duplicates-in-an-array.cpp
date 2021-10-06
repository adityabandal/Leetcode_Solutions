class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i+1) continue;
            else{
                if(nums[i] == nums[nums[i]-1]) continue;
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        // for(int x:nums) cout<<x<<" "; cout<<endl;
        return ans;
    }
};