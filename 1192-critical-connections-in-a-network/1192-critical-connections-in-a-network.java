class Solution {
    List<List<Integer>> graph;
    List<List<Integer>> bridges;
    int[] disc, low;
    int timer = 0;

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {

        graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());

        for (List<Integer> e : connections) {
            int u = e.get(0), v = e.get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        disc = new int[n];
        low = new int[n];
        Arrays.fill(disc, -1);
        bridges = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (disc[i] == -1)
                dfs(i, -1);
        }
        return bridges;
    }
private void dfs(int u, int parent) {
        disc[u] = low[u] = timer++;

        for (int v : graph.get(u)) {
            if (v == parent) continue;

            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    bridges.add(Arrays.asList(u, v));
                }
            } else {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
}