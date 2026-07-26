class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n= s.size();
        int m= t.size();
        stack<char> st1;
        stack<char> st2;
        string first ="";
        string second ="";

        for(auto ch: s){
            if(ch >= 'a' && ch<= 'z'){
                st1.push(ch);
            }else{
                if(!st1.empty() && ch=='#'){
                    st1.pop();
                }
            }
        }
        while(!st1.empty()){
            first += st1.top();
            st1.pop();
        }

        for(auto ch: t){
            if(ch >= 'a' && ch<= 'z'){
                st2.push(ch);
            }else{
                if(!st2.empty() && ch=='#'){
                    st2.pop();
                }
            }
        }
        while(!st2.empty()){
            second += st2.top();
            st2.pop();
        }
        return (first == second);
    }
};