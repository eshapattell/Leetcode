class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int> left(n), right(n);
        stack <int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();


        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // for(auto &e: left) cout<<e<<" ";cout<<endl;
        // for(auto &e: right) cout<<e<<" ";cout<<endl;
        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i=0;i<n;i++){
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans= (ans + (leftCount * rightCount % mod)* arr[i] %mod) %mod;
        }
        return ans;

    }
};