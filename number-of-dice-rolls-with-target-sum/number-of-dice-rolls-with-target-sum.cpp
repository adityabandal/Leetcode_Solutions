#define M 1000000007
class Solution {
public:
    // td = 0 to target-d
    // par = d-1 to 0
    int dp[31][1001];
    int help(int par, int mx, int td){
        // cout<<td<<endl;
        // if(td<0){
        //     return 1;
        // }
        if(td>(mx-1)*(par+1)) return -1;
        // cout<<td<<" "<<par<<endl;
        if(par==0 || td==0) return 1;
        if(dp[par][td] != -1) return dp[par][td];
        int ans = 0;
        for(int i=0;i<min(mx, td+1);i++){
            int nxt = help(par-1, mx, td-i);
            if(nxt!=-1)
                ans = (ans+nxt)%M;
        }
        return dp[par][td]=ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        if(target<d || target>f*d) return 0;
        // int td = targetarget- d;
        memset(dp, -1, sizeof(dp));
        return help(d-1, f, target-d);
    }
};

/*
    d
    1,1,1...d times => d
    f,f,f...d times => d.f
    
    _ _ _ _ _ _... d boxes => (target-d)^d
    
    _ _ _ _ _ ... target-d times
    
    f-1 each partition
    
   
   8,1
   

*/