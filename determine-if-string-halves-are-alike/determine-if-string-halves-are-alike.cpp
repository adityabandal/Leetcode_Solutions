class Solution {
public:
    bool isVow(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(isVow(s[i])) cnt++;
        }
        for(int i=n/2;i<n;i++){
            if(isVow(s[i])) cnt--;
            if(cnt<0) return false;
        }
        return cnt==0;
    }
};