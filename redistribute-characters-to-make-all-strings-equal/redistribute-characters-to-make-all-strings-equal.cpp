class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> arr(26, 0);
        
        for(string w:words){
            for(char c:w){
                arr[c-'a']++;
            }
        }
        
        int n = words.size();
        
        for(int i=0;i<26;i++){
            if(arr[i]%n!=0) return false;
        }
        return true;
    }
};