class Solution {
public:
    int dfs(int i, vector<vector<int>> &x, vector<int>& informTime, int mx = 0) {
        for (auto d:x[i]) mx=max(mx,dfs(d,x,informTime));
        return informTime[i]+mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> x(n);
        for(auto i=0; i<manager.size();i++) if (manager[i]!=-1)  x[manager[i]].push_back(i);
        return dfs(headID,x,informTime);
    }
};