class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        
        int maxp=1,maxn=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                maxp = max(nums[i],nums[i]*maxp);
                maxn = min(nums[i],nums[i]*maxn);
                ans = max(ans,maxp);
            }
            else if(nums[i]<0){
                int p = maxp;
                int n = maxn;
                
                maxp = max(nums[i],n*nums[i]);
                maxn = min(nums[i],p*nums[i]);
                ans = max(ans,maxp);
            }
            else{
                maxp=1;
                maxn=1;
                ans = max(ans,0);
            }
            
            
            cout<<ans<<" ";
        }
        
        return ans;
    }
};