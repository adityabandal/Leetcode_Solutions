class Solution {
public:
    int maxv(vector<int>& arr){
        int mx = INT_MIN;
        for(int a:arr){
            mx = max(mx, a);
        }
        return mx;
    }
    double time(vector<int>& arr, double speed){
        double sum =0;
        // cout<<speed<<endl;
        for(int i=0;i<arr.size()-1;i++){
            // cout<<ceil((double)arr[i]/speed)<<" ";
            sum += ceil((double)arr[i]/speed);
        }
        sum += ((double)arr[arr.size()-1]/speed);
        // cout<<endl;
        return sum;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int hi = 100000000;
        int lo = 1;
        
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            
            double t = time(dist, mid);
            if(t<=hour){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};