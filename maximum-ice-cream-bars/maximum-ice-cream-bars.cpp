class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        
        int ans = 0;
        int i = 0;
        while(i<costs.size() && costs[i]<=coins){
            ans++;
            coins -= costs[i];
            i++;
        }
        return ans;
    }
};