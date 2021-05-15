#include <regex>
regex r(R"(^\s*[-+]?(((\d{1,})(\.\d{1,})?)|(\d{1,}\.)|(\.\d{1,}))([Ee][-+]?\d{1,})?\s*$)");
class Solution {
public:
//     bool is_int(string s){
//         if(s.size()==0) return false;
//         if(s[0]=='+' || s[0]=='-'){
//             return s.size()>1;
//         }
//         else{
//             return s.size()>0;
//         }
//     }
//     bool is_dec(string s){
//         size_t found = s.find('.');
//         if (found == string::npos)
//             return is_int(s);
//         else{
//             string s1 = string s1 = s.substr(0, found);
//             string s2 = s.substr(found+1, s.size()-found);
            
//             // if()
//         }
//         return true;
//     }
    bool isNumber(string s) {
        
        return regex_match(s, r);
        // int cnt = 0;
        // int e_pos = -1;
        // for(int i=0;i<s.size();i++){
        //     char ch = s[i];
        //     if((ch>='a'&&ch<='z')||ch>='A'&&ch<='Z'){
        //         cnt++;
        //         if(ch=='e' || ch=='E'){
        //             e_pos=i;
        //         }
        //     }
        // }
        // if(cnt>=2 || (cnt>0 && e_pos==-1)) return false;
        // if(e_pos!=-1){
        //     string s1 = s.substr(0, e_pos);
        //     string s2 = s.substr(e_pos+1, s.size()-e_pos);
        //     cout<<s1<<" "<<s2<<endl;
        //     return is_dec(s1) && is_int(s2);
        // }
        // else{
        //     cout<<s<<endl;
        //     return is_dec(s);
        // }
        // return true;
    }
};