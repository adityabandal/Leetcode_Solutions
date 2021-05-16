#define pi pair<int, int>
#define f second
#define s first
class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        
        int t = 1;
        while(max(m1, m2)>=t){
            if(m1>=m2){
                m1-=t;
            }
            else{
                m2-=t;
            }
            t++;
        }
        
        
        return {t, m1, m2};
    }
};