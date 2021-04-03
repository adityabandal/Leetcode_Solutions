class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c == '('){
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int start = st.top();
                    ans = max(ans, i-start);
                    
                }
            }
        }
        return ans;
    }
};