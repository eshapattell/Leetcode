class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        int n = s.size()-1;
        for(int i=0;i<n;i++){
                if(s[i]=='(' && !st.empty()){
                    ans += '(';
                    st.push(s[i]);
                }
                else if(s[i]=='(' && st.empty()){
                    st.push(s[i]);
                }
                else if(s[i] ==')'){
                    st.pop();
                    if(!st.empty()){
                        ans += ')';
                    }else{
                        continue;
                    }
                }
        }
        return ans;
    }
};