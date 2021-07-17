class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                int nt = target - nums[i] - nums[j];
                int lo = j+1, hi = n-1;
                while(lo<hi){
                    int sum = nums[lo]+nums[hi];
                    if(sum<nt || (lo>j+1 && nums[lo]==nums[lo-1])){
                        lo++;
                    }
                    else if(sum>nt || (hi<n-1 && nums[hi]==nums[hi+1])){
                        hi--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[lo++], nums[hi--]});
                    }
                }
            }
        }
        return ans;
    }
};