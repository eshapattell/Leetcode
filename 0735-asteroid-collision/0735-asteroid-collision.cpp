class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(auto ch : asteroids){
            if(ch >0){
                st.push(ch);
            }else{
                bool destroyed =false;
                while(!st.empty() && st.top() > 0){
                    if(st.top() < abs(ch)){
                            st.pop();
                    }else if(st.top() == abs(ch)){
                        st.pop();
                        destroyed =true;
                        break;
                    }else{
                        break;
                        destroyed= true;
                    }
                }
                if(!destroyed && (st.empty() || st.top() < 0)){
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};