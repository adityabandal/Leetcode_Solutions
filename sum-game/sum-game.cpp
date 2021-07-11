class Solution {
public:
    bool sumGame(string num) {
        int l=0, r=0, lq=0, rq=0;
        int n = num.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?') lq++;
                else l+=(num[i]-'0');
            }
            else{
                if(num[i]=='?') rq++;
                else r+=(num[i]-'0');
            }
        }
        
        int diff = l-r;
        int total = lq+rq;
        
        
        int mx = min((total-1)/2+1, lq)*9;
        int mn = min((total-1)/2+1, rq)*9;
        // cout<<diff+mx<<" "<<diff-mn<<endl;
        
        
            return mx+diff > 9*min(total/2, rq) || abs(diff-mn) > 9*min(total/2, lq);
    
    }
};