#define ull unsigned long
class Solution {
public:
    bool isP(ull n){
        ull k = n;
        ull c = 0;
        while(k){
            c = 10*c + k%10;
            k/=10;
        }
        return c == n;
    }
    
    int superpalindromesInRange(string left, string right) {
        ull L = stoul(left);
        ull R = stoul(right);
        ull M = 100000;
        ull cnt = 0;
        for(int i=1;i<M;i++){
            string s = to_string(i);
            
            for(int j = s.size()-2;j>=0;j--){
                s.push_back(s[j]);
            }
            
            ull v = stoul(s);
            v *=v;
            if(v > R) break;
            if(v>=L && isP(v)) {
                // cout<<v<<endl;
                cnt++;
            }
        }
        for(int i=1;i<M;i++){
            string s = to_string(i);
            // cout<<s<<' ';
            for(int j = s.size()-1;j>=0;j--){
                s.push_back(s[j]);
            }
            // cout<<s<<endl;
            ull v = stoul(s);
            v *=v;
            if(v > R) break;
            if(v>=L && isP(v)) {
                // cout<<v<<endl;
                cnt++;
            }
        }
        // cout<<endl;
        return cnt;
    }
};