class Solution {
public:
//     int helper(vector<int>& prices, int i, int t,bool  b){
//         if(i>=prices.size() || t==2) return 0;
//         if(b){
            
//         }
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int h1=INT_MIN,h2=INT_MIN;
        int r1=0,r2=0;
        for(int p:prices){
            r2 = max(r2, h2+p);
            h2 = max(h2, r1-p);
            r1 = max(r1, h1+p);
            h1 = max(h1, -p);
        }
        return r2;
    }
};