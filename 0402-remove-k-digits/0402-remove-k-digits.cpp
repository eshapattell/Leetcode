class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;

        for(char ch : num) {

            while(!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }

            st.push_back(ch);
        }

        // If k is still remaining,
        // remove digits from the end.
        while(k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;

        while(i < st.size() && st[i] == '0') {
            i++;
        }

        // Everything was removed or became zero
        if(i == st.size()) {
            return "0";
        }

        return st.substr(i);
    }
};