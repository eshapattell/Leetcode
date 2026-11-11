class Solution {
public:
int dfs(int node,vector<vector<int>>&adj,vector<int>&subtree)
{
    int size=1;
    for(int i=0;i<adj[node].size();i++)
    {
        size+=dfs(adj[node][i],adj,subtree);
    }
    subtree[node]=size;
    return size;
}
    int countHighestScoreNodes(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>adj(n);
        vector<int>subtree(n);
        for(int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        dfs(0,adj,subtree);
        long long maxi=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            long long score=1;
            for(int j=0;j<adj[i].size();j++)
            {
                score*=subtree[adj[i][j]];
            }
            int remain=n-subtree[i];
            if(remain>0)
            {
                score*=remain;
            }
            if(score>maxi)
            {
                maxi=score;
                ans=1;
            }
            else if(score==maxi)
            {
                ans++;
            }
        }
        return ans;
    }
};