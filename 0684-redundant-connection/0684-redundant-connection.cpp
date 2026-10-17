class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1), rank(n+1, 1);
        for(int i=0; i<=n; ++i)
           par[i] = i; //Initially every node is it's own parent
        
        //Main loop
        for(const auto& edge: edges){
            if(!Union(par, rank, edge[0], edge[1]))
                return vector<int>{edge[0], edge[1]};
        }
        return {};
    }

private:
    // Path Compression
    int Find(vector<int>& par, int n){
        int p = par[n];
        while(p != par[p]){
            par[p] = par[par[p]]; //Path compression
            //that makes every other node point to its grandparent as you traverse, flattening the tree over time so future Find calls are faster.
            p = par[p];
        }
        return p;
    }

    //Find both roots. If they're the same, the nodes are already in one connected component — adding this edge would create a cycle, so return false.
    //Otherwise, merge the smaller tree under the larger one (union by size), and return true.
    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);

        if(p1 == p2) return false;

        if(rank[p1]>rank[p2]){
            par[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            par[p1] = p2;
            rank[p2] += p1;
        }

        return true;
    }
};