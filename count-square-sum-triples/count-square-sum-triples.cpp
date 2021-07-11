class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=5;i<=n;i++){
            for(int j=1;j<i;j++){
                int a = i*i-j*j;
                int a2 = sqrt(a);
                // cout<<a<<" "<<a2<<endl;
                if(a2*a2==a) ans++;
            }
        }
        return ans;
    }
};