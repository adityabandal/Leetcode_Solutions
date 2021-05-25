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
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=1) return 0;
        vector<int> left(n), right(n);
        
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1], height[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(left[i], right[i])-height[i];
        }
        // printv(left);
        // printv(right);
        return ans;
    }
};