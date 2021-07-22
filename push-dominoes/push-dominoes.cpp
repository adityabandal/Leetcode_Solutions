class Solution {
public:
    string pushDominoes(string s) {
        string d = '.'+s;
        vector<int> arr(d.size(), 0);
        int n = d.size();
        int curr = INT_MIN;
        for(int i=0;i<n;i++){
            if(d[i]=='R'){
                curr = i;
            }
            if(d[i]=='L'){
                curr = INT_MIN;
            }
            arr[i] = curr;
        }
        // for(int x:arr) cout<<x<<" "; cout<<endl;
        curr = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(d[i]=='R'){
                curr = INT_MIN;
            }
            if(d[i]=='L'){
                
                curr = i;
            }
            if(curr!=INT_MIN){
                if(arr[i]==INT_MIN){
                    arr[i] = -curr;
                }
                else if(abs(curr-i)<abs(arr[i]-i)){
                    arr[i] = -curr;
                }
                else if(abs(curr-i)>abs(arr[i]-i)){
                    
                }
                else{
                    arr[i] = INT_MIN;
                }
            }
        }
        string ans = "";
        for(int x:arr){
            if(x==INT_MIN){
                ans.push_back('.');
            }
            else if(x<=0){
                ans.push_back('L');
            }
            else{
                ans.push_back('R');
            }
        }
        return ans.substr(1);
    }
};