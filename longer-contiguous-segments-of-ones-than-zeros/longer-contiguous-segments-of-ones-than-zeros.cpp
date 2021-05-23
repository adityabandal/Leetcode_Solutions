class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        
        int o = 0, z=0;
        bool w;
        if(s[0] == '1'){
            w = true;
            o++;
        }
        else{
            w = false;
            z++;
        }
        int maxo = 0, maxz=0;
        for(int i=1;i<n;i++){
            
            if(w && s[i]=='1') o++;
            else if(!w && s[i]=='0') z++;
            else if(w && s[i] == '0'){
                maxo = max(maxo, o);
                o=0;
                z=1;
                w = false;
            }
            else if(!w && s[i] == '1'){
                maxz = max(maxz, z);
                z = 0;
                o=1;
                w= true;
            }
            // cout<<o<<" "<<z<<endl;
        }
        maxo = max(maxo, o);
        maxz = max(maxz, z);
        // cout<<maxo<<" "<<maxz<<endl;
        return maxo>maxz;
    }
};