class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(int i=0;i<str.size();i++){
            // cout<<"hi"<<endl;
            if(str[i]=='(') s.push('a');
            else if(str[i]=='[') s.push('b');
            else if(str[i]=='{') s.push('c');
            else if(str[i]==')'){
                if(s.empty() || s.top()!='a') return 0;
                else{
                    s.pop();
                }
            }
            else if(str[i]==']'){
                if(s.empty() || s.top()!='b') return 0;
                else{
                    s.pop();
                }
            }
            else if(str[i]=='}'){
                if(s.empty() || s.top()!='c') return 0;
                else{
                    s.pop();
                }
            }
        }
        return s.empty();
    }
};