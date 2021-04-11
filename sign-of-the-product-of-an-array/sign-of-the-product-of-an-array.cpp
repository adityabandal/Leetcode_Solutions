class Solution {
public:
    int arraySign(vector<int>& nums) {
        int s = 1;
        for(int n:nums){
            if(n<0){
                s*=-1;
            }
            else if(n==0){
                return 0;
            }
        }
        return s;
    }
};