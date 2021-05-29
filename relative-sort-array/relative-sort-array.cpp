class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int dp[1001] = {};
        for(int n:arr1) dp[n]++;
        int idx = 0;
        for(int n:arr2){
            while(dp[n]-->0){
                arr1[idx++] = n;
            }
        }
        for(int i=1;i<=1000;i++){
            while(dp[i]-->0){
                arr1[idx++] = i;
            }
        }
        return arr1;
    }
};

/*
    S - n
    T - n + nlogn
    hmap arr[i] = i
         !found = INTMAX
    sort(comp->hmap)
    
*/