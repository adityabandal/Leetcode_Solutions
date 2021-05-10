class Solution {
public:
    
    int countPrimes(int n) {
        if(n<=2) return 0;
        bool p[n];
        memset(p, true, sizeof(p));
        p[0] = p[1] = false;
        
        for(int i=2;i<sqrt(n);i++){
            if(!p[i]) continue;
            for(int j = i*i;j<n;j+=i){
                p[j] = false;
            }
        }
        
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(p[i]) cnt++;
        }
        
        return cnt;
    }
};