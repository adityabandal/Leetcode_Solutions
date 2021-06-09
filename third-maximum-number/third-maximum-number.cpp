class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int f,s,t;
        f = s = t = LONG_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>f){
                t = s;
                s = f;
                f = nums[i];
            }
            else if(nums[i] == f) continue;
            else if(nums[i]>s){
                t=s;
                s = nums[i];
            }
            else if(nums[i] == s) continue;
            else if(nums[i]>t){
                t = nums[i];
            }
        }
        return t != LONG_MIN?t:f;
    }
};