class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //build the adjacency list
        // adj[u] stores {v, w}, meaning an edge from u to v, with travel time w.
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }
        //create a min-heap
        // Each pair contains {distance, node},the node with the smallest distance comes out first.
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        //initialize distances
        //initially, all nodes are considered unreachable.
        vector<int> dist(n + 1, 1e9);

        //distance from the source node k to itself is 0.
        dist[k]= 0;
        pq.push({0,k});

        while(!pq.empty()){
            //get the node with the smallest current distance.
            auto [dis, node] = pq.top();
            pq.pop();

            //skip an outdated entry in the priority queue.
            if(dis > dist[node])
                continue;
            
            //explore all neighbours of the current node.
            for(auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;


                //check whether going through this node gives a shorter path to its neighbour.
                if(dis + wt < dist[adjnode]) {

                    //update the shortest known distance.
                    dist[adjnode] = dis + wt;
                    //push the updated distance and node.
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        //find the maximum shortest distance, the signal must reach the farthest node.
        int ans = 0;
        for(int i = 1; i <= n; i++) {

            //if any node is unreachable, return -1.
            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }
        //time needed for the signal to reach every node.
        return ans;
    }
};