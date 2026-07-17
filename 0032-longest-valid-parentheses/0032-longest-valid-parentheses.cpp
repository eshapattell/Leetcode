class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n= s.size();
        vector<int> visited(n);

        for(int i=0;i<n;i++){
            if(s[i]== '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    visited[i]=1;
                    visited[st.top()]=1;
                    st.pop();
                }
            }
        }
        int maxCount=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                curr++;
                maxCount= max(maxCount, curr);
            }else{
                curr=0;
            }
        }
        return maxCount;
    }
};