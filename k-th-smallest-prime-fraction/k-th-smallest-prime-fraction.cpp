class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(i!=j){
                    pq.push({(double)((double)arr[i]/(double)arr[j]),{arr[i], arr[j]}});
                }
            }
        }
        while(--k){
            // cout<<pq.top().first<<"->"<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            pq.pop();
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};