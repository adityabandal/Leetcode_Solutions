class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        if(l<=1)    return 0;
        int s=0;
        int b=1;
        if(prices[0]<=prices[1]){
            s-=prices[0];
            b=0;
        }
        for(int i=1;i<l-1;i++){
            if(b==0 && prices[i-1]<=prices[i] && prices[i+1]<=prices[i]){
                s+=prices[i];
                b=1;
            }
            if(b==1 && prices[i-1]>=prices[i] && prices[i+1]>=prices[i]){
                s-=prices[i];
                b=0;
            }
        }
        if(b==0 && prices[l-2]<=prices[l-1]){
            s+=prices[l-1];
            b=1;
        }
        if(s<0) return 0;
        return s;
    }
};