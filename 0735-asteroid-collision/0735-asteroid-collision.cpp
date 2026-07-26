class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int ch : asteroids){
            //asteroid is positive and moving in right dir
            if(ch > 0){
                st.push(ch);
            }else{
                //for asteroid moving towards left
                //to check if curr asteroid is destroyed or not
                bool destroyed= false;
                while(!st.empty() && st.top() >0){
                    //curr asteroid is larger
                    if(st.top() < abs(ch)){
                        st.pop();
                    }else if(st.top() == abs(ch)){
                        //both are of same size so both get destroyed
                        st.pop();
                        destroyed= true;
                        break;
                    }else{
                        //the top element of the stack is bigger
                        break;
                        destroyed =true;
                    }
                }
                //curr asteroid not destroyed and the stack is empty or top ele is also in left dir meaning it will never collide
                if(!destroyed && (st.empty() || st.top() <0)){
                    st.push(ch);
                }
            }
        }
        //emptying the stack
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        //reversing the stack output
        reverse(ans.begin(),ans.end());
        return ans;
    }
};