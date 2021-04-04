#define M 1000000007
class Solution {
public:
    int rev(int n){
        int ans = 0;
        while(n){
            ans = 10*ans+n%10;
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);
        unordered_map<long long int ,long long int> m;
        for(int i=0;i<n;i++){
            r[i] = rev(nums[i]);
            m[nums[i]-r[i]]++;
            // cout<<nums[i]-r[i]<<" ";
        }
        long long int ans=0;
        for(auto p:m){
            long long int c = p.second;
            ans = (ans + (c*(c-1)/2))%M;
        }
        return ans%M;
    }
};