class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        if(target>nums.back()) return n;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]<target){
                lo = mid+1;
            }
            else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};