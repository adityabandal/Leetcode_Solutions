class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for(int a:nums){
            x|=a;
        }
        return x*(1<<n-1);
    }
};