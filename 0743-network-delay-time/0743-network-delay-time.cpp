class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k-- ;//for making 0indexing
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s-1].push_back({d-1,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d>dist[node]) continue;
            for(int j=0;j<a[node].size();j++){
                int neg = a[node][j].first;
                int wt = a[node][j].second;
                if(d+wt < dist[neg]){
                    dist[neg] = d+wt;
                    pq.push({d+wt,neg});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<dist.size();i++){
            if(dist[i] == INT_MAX)
                return -1;
            else
                ans = max(ans,dist[i]);
        }
        return ans;
    }
};