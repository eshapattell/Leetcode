class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;

        for (int num : nums2) {

            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> ans;

        for (int num : nums1) {
            if (nextGreater.find(num) != nextGreater.end()) {
                ans.push_back(nextGreater[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};