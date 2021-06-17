class Solution {
public:
    int help(vector<int>& arr, int b){
        int ans = 0;
        int curr = 0;
        for(int x:arr){
            if(x<=b) curr++;
            else curr = 0;
            ans += curr;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        return help(arr, right)-help(arr, left-1);
    }
};