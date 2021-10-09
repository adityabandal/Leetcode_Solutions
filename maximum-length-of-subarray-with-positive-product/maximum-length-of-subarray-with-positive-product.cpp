class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int prod = 1;
        int n = nums.size();
        int pos = -1;
        int neg = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                prod = 1;
                pos = i;
                neg = -1;
            }
            else{
                prod *= nums[i]/abs(nums[i]);
                if(prod>0){
                    
                    ans = max(ans, i-pos);
                }
                else{
                    if(neg == -1){
                        neg = i;
                    }
                    ans = max(ans, i-neg);
                }
            }
        }
        
        return ans;
    }
};