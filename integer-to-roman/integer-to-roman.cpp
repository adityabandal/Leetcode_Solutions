class Solution {
public:
    unordered_map<int, char> m;
    string intToRoman(int num) {
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';
        
        int d[4];
        memset(d, 0, sizeof(d));
        
        for(int i=3;i>=0;i--){
            d[i] = num%10;
            num/=10;
        }
        
        string ans = "";
        for(int i=0;i<d[0];i++) ans+=m[1000];
        int x = d[1];
        if(x){
            if(x<=3)
                for(int i=0;i<x;i++) ans+=m[100];
            else if(x==4) ans+="CD";
            else if(x==5)
                ans+=m[500];
            else if(x<=8){
                ans+=m[500];
                for(int i=0;i<x-5;i++) ans+=m[100];
            }
            else if(x==9) ans+="CM";
        }
        x = d[2];
        if(x){
            if(x<=3)
                for(int i=0;i<x;i++) ans+=m[10];
            else if(x==4) ans+="XL";
            else if(x==5)
                ans+=m[50];
            else if(x<=8){
                ans+=m[50];
                for(int i=0;i<x-5;i++) ans+=m[10];
            }
            else if(x==9) ans+="XC";
        }
        x = d[3];
        if(x){
            if(x<=3)
                for(int i=0;i<x;i++) ans+=m[1];
            else if(x==4) ans+="IV";
            else if(x==5)
                ans+=m[5];
            else if(x<=8){
                ans+=m[5];
                for(int i=0;i<x-5;i++) ans+=m[1];
            }
            else if(x==9) ans+="IX";
        }
        return ans;         
    }
};