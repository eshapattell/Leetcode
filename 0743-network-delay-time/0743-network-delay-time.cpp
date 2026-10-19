class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adj list to store the adge
        vector<vector<pair<int,int>>>adj(n);

        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            //treating index 1 as 0
            adj[u-1].push_back({v-1, w});
        }
    
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<int> dist(n, 1e9);

        //dist from src to itself
        dist[k-1]= 0;
        pq.push({0,k-1});

        while(!pq.empty()){
            auto [dis, node]= pq.top();
            pq.pop();

            //if curr is greater 
            if(dis > dist[node])continue;

            //neighbors of curr node
            for(auto &it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;

                //if it gives the shortest dist
                if(wt +dist[node] < dist[adjNode]){
                    dist[adjNode]= dis+ wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        //max shortest dist
        int ans=0;
        for(int i=0;i< n;i++){
            //if a node cant be reached
            if(dist[i]==1e9){
                return -1;
            }
            ans= max(ans, dist[i]);
        }

        return ans;
    }
};