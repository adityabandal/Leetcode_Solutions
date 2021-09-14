class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        
        int lo = 0, hi = n-1;
        
        while(lo<hi){
            while(lo<hi && !((s[lo]>='a' && s[lo]<='z') || (s[lo]>='A' && s[lo]<='Z'))) lo++;
            while(lo<hi && !((s[hi]>='a' && s[hi]<='z') || (s[hi]>='A' && s[hi]<='Z'))) hi--;
            
            swap(s[lo++], s[hi--]);
        }
        
        return s;
    }
};