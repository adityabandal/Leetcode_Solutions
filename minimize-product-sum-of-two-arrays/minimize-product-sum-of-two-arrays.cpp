#define all(nums) nums.begin(), nums.end()
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(all(nums1));
        sort(all(nums2));
        int ans = 0;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            ans += nums1[i]*nums2[n-1-i];
        }
        return ans;
    }
};