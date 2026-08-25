class Solution {
public:
    string removeDuplicates(string s, int k) {
        // first  = character
        // second = current consecutive frequency
        stack<pair<char, int>> st;

        for(char ch : s) {
            // if stack is not empty and current character
            // is same as the character on top
            if(!st.empty() && st.top().first == ch) {

                // increase its consecutive count
                st.top().second++;

                // if count becomes exactly k,
                // remove the whole group
                if(st.top().second == k) {
                    st.pop();
                }
            }

            else {
                // different character starts a new group
                st.push({ch, 1});
            }
        }
        string ans = "";

        // stack is in reverse order,
        // so build answer from top to bottom
        while(!st.empty()) {

            char ch = st.top().first;
            int count = st.top().second;

            // add the character count times
            while(count--) {
                ans += ch;
            }

            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};