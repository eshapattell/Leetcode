class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m);
        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    arr[j]++;
                }else{
                    arr[j] = 0;
                }
            }

            vector<int> prev(m);
            vector<int> next(m);
            stack<int> st;

            for(int x = 0; x < m; x++){
                while(!st.empty() && arr[st.top()] >= arr[x]){
                    st.pop();
                }

                if(st.empty()){
                    prev[x] = -1;
                }else{
                    prev[x] = st.top();
                }
                st.push(x);
            }

            while(!st.empty()){
                st.pop();
            }

            for(int x = m-1; x >= 0; x--){
                while(!st.empty() && arr[st.top()] >=  arr[x]){
                    st.pop();
                }

                if(st.empty()){
                    next[x] = m;
                }else{
                    next[x] = st.top();
                }

                st.push(x);
            }

            int height = 0;
            int width = 0;
            int curr = 0;
            int maxArea = 0;

            for(int x = 0; x < m; x++){
                width = next[x] - prev[x] - 1;
                height = arr[x];
                curr = width * height;
                maxArea = max(curr,maxArea);
            }

            ans = max(ans,maxArea);

        }

        return ans;
    }
};