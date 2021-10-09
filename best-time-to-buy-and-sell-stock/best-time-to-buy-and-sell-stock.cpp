class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> arr(n);
        arr[0] = prices[0];
        for(int i=1;i<n;i++){
            arr[i] = min(arr[i-1], prices[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, prices[i]-arr[i]);
        }
        
        return ans;
    }
};