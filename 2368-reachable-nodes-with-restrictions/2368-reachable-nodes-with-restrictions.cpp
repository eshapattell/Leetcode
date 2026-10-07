class Solution {
public:
    void solve(int node, unordered_map<int, vector<int>>& adj,
               vector<int>& vis, vector<int>& res, int& ans) {
        
        if (res[node] == 1) return;

        ans++;
        vis[node] = 1;

        for (auto nbr : adj[node]) {
            if (vis[nbr] == 0) {
                solve(nbr, adj, vis, res, ans);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> res(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < restricted.size(); i++) {
            res[restricted[i]] = 1;
        }

        vector<int> vis(n, 0);
        int ans = 0;

        solve(0, adj, vis, res, ans);

        return ans;
    }
};