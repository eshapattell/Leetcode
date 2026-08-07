class Solution {
public:

    void helper(vector<int>& nge, stack<int>& st, int n, vector<int>& nums){

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();

            st.push(nums[i]);
        }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        stack<int> st;
        vector<int> nge(n);

        helper(nge, st, n, nums);
        helper(nge, st, n, nums);

        return nge;
    }
};