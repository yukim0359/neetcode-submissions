class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[node]) return false;
        visited[node] = true;

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            if (!dfs(nei, node, adj, visited)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n, false);

        if (!dfs(0, -1, adj, visited)) return false;

        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};
