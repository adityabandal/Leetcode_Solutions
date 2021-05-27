class Solution {
public:
    int bit(string w){
        int n = 0;
        for(int i=0;i<w.size();i++){
            // cout<<w[i];
            n |= (1<<(w[i]-'a'));
        }
        // cout<<endl<<n<<endl;;
        return n;
    }
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for(const string& w:words){
            bits.push_back(bit(w));
        }
        
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!(bits[i]&bits[j])){
                    ans = max(ans, (int)(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};