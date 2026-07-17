class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n= s.size();
        st.push(-1);
        int maxCount= 0;

        for(int i=0;i<n;i++){
            if(s[i]== '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxCount= max(maxCount,i - st.top());
                }
            }
        }
        return maxCount;
    }
};

//time-complexity: O(n);
//space-complexity: O(1);