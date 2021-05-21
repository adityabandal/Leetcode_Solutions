class Solution {
public:
    string lcp(string s1, string s2){
        int ans=0;
        for(int i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i]==s2[i]){
                ans++;
            }
            else{
                break;
            }
        }
        return s1.substr(0,ans);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            ans = lcp(ans,strs[i]);
        }
        return ans;
    }
};