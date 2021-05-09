#define ull unsigned long long
#define M 1000000007
#define MVAL 10000000
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<ull> cum(n+1, 0);
        for(int i=1;i<=n;i++){
            cum[i] = cum[i-1]+nums[i-1];
        }
        
        ull ans = 0;
        vector<int> L(n), R(n);
        
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]) st.pop();
            L[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && nums[st.top()]>=nums[i]) st.pop();
            R[i] = st.top();
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            int curr = nums[i];
            int l = L[i];
            int r = R[i];
            // cout<<i<<" "<<l<<" "<<r<<endl;
            
            ull mp = (cum[r]-cum[l+1])*(ull)nums[i];
            ans = max(ans, mp);
        }
        
        return ans%M;
    }
};