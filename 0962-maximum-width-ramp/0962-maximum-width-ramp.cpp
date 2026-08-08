class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        stack<int> st;

        // Step 1: store possible left indices
        for(int i = 0; i < n; i++) {

            if(st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int ans = 0;

        // Step 2: scan from right
        for(int j = n - 1; j >= 0; j--) {

            while(!st.empty() && nums[st.top()] <= nums[j]) {

                int i = st.top();
                st.pop();

                ans = max(ans, j - i);
            }
        }

        return ans;
    }
};