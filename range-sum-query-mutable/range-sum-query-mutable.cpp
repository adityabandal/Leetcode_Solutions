class NumArray {
public:
    vector<int> arr;
    int offset;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            arr = vector<int>(1);
            arr[0] = nums[0];
            offset = 0;
        }
        else{
            int p = log2(n-1)+2;
            int N = pow(2, p)-1;
            // cout<<n<<" "<<N<<endl;
            offset = pow(2, p-1)-1;
            // cout<<offset<<endl;
            arr = vector<int>(N, 0);
            for(int i=0;i<n;i++){
                int idx = offset+i;
                // arr[idx] = nums[i];
                while(idx!=0){
                    arr[idx] += nums[i];
                    idx = (idx-1)/2;
                }
                arr[0] += nums[i];
            }
            // for(int x:arr) cout<<x<<" "; cout<<endl;
        }
        
    }
    
    void update(int index, int val) {
        int diff = val - arr[offset+index];
        int idx = offset+index;
        while(idx!=0){
            arr[idx] += diff;
            idx = (idx-1)/2;
        }
        arr[0] += diff;
        // for(int x:arr) cout<<x<<" "; cout<<endl;
    }
    int help(int idx, int l, int r, int lo, int hi){
        if(lo>hi) return 0;
        // cout<<lo<<" "<<hi<<endl;
        if(lo>r || hi<l) return 0;
        if(lo>=l && hi<=r) return arr[idx];
        else{
            int mid = lo+(hi-lo)/2;
            return help(2*idx+1, l, r, lo, mid)+help(2*idx+2, l, r, mid+1, hi);
        }
    }
    int sumRange(int left, int right) {
        return help(0, left, right, 0, offset);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */