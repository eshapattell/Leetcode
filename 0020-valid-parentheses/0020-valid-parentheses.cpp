class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch :s){
            //for opening bracket
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
                
            //closing brackets
            }else{
                //no opening brackets
                if(st.empty()){
                    return false;
                }
                //checking the top element in the stack
                if((ch==')' && st.top() == '(')||
                   (ch==']' && st.top() == '[')||
                   (ch=='}' && st.top() == '{')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        //if stack is not empty it means brackets left in stack,return false
        return st.empty();
    }
};

//time complexity: O(n);
//space complexity: O(n);