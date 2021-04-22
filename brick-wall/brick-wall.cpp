class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long int sum = 0;
        int n = wall.size();
        unordered_map<long long int, int> m;
        for(int b:wall[0]) sum+=b;
        for(int i=0;i<n;i++){
            int c = 0;
            for(int b:wall[i]){
                c+=b;
                m[c]++;
            }
        }
        int ans = INT_MIN;
        for(auto p:m){
            // cout<<p.first<<" "<<p.second<<endl;
            if(p.first!=0 && p.first!=sum)
            ans = max(ans, p.second);
        }
        // cout<<endl;
        return (ans==INT_MIN)?n:n-ans;
    }
    
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();