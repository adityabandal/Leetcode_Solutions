class Solution {
public:
    void printv(vector<int> arr,string name="", int n=-1){
        cout<<name<<" ";
        if(n==-1)n=arr.size();
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        // int n = arr1.size();
        // int m = arr2.size();
        
        // int total = n*m;
        
        vector<int> b1(32, 0), b2(32, 0);
        for(int a:arr1){
            int i=0;
            while(a){
                b1[i] += a%2;
                a/=2;
                i++;
            }
        }
        for(int a:arr2){
            int i=0;
            while(a){
                b2[i] += a%2;
                a/=2;
                i++;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            if(b1[i]%2 && b2[i]%2){
                ans |= 1<<i;
            }
        }
        // printv(b1);
        // printv(b2);
        return ans;
    }
};