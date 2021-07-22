class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        
        arr[0] = nums[0];
        
        for(int i=1;i<n;i++){
            arr[i] = max(arr[i-1], nums[i]);
        }
        
        int curr = INT_MAX;
        int ans = -1;
        for(int i=n-1;i>0;i--){
            curr = min(curr, nums[i]);
            if(curr>=arr[i-1]){
                ans = i;
            }
        }
        return ans;
    }
};