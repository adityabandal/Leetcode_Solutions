class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(mid == n-1) return mid;
            if(nums[mid]<=nums[mid+1]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
    }
};