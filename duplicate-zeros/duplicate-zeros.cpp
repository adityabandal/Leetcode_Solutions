class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int curr = 0;
        int ins = 0;
        while(ins<arr.size()){
            if((arr[curr]%10)!=0){
                arr[ins] += 10*(arr[curr]%10);
                curr++;
                ins++;
            }
            else{
                curr++;
                ins+=2;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=arr[i]/10;
        }
    }
};