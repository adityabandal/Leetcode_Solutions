class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();
        int arr[l1][l2];
        int i,j;
        if(text1[0]==text2[0]) arr[0][0]=1;
        else arr[0][0]=0;
        for(i=1;i<l2;i++)
        {
            if(text1[0]==text2[i]){
                arr[0][i]=1;
            }
            else{
                arr[0][i]=arr[0][i-1];
            }
        }
        for(i=1;i<l1;i++)
        {
            if(text1[i]==text2[0]){
                arr[i][0]=1;
            }
            else{
                arr[i][0]=arr[i-1][0];
            }
        }
        for(i=1;i<l1;i++){
            for(j=1;j<l2;j++){
                if(text1[i]==text2[j]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[l1-1][l2-1];
    }
};