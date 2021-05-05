class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int mx = nums[0];
        int curr = nums[0];
        int jmp = 1;
        for(int i=1;i<nums.size();i++){
            if(i>curr){
                curr = mx;
                jmp++;
                // cout<<i<<endl;
            }
            mx = max(mx, i+nums[i]);
        }
        return jmp;
    }
};