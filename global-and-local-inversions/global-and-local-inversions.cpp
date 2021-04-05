class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if(n<=2) return true;
        for(int i=0;i<n-1;i++){
            if(A[i]==i) continue;
            else if(A[i]==i+1 && A[i+1]==i){
                i++;
            }
            else return false;
        }
        return true;
    }
};