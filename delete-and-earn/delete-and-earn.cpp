class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[10001];
        memset(arr, 0, sizeof(arr));
        
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]+=nums[i];
        }
        
        int pprev = 0;
        int prev = 0;
        
        for(int i=0;i<=10000;i++){
            int curr = max(prev, pprev+arr[i]);
            pprev = prev;
            prev = curr;
        }
        
        return prev;
    }
};