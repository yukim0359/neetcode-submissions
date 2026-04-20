class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[node] == 1) return;
        visited[node] = 1;
        for (int e: graph[node]) {
            dfs(e, graph, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> graph(n);

        for (auto& e: edges) {
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(i, graph, visited);
                ans++;
            }
        }

        return ans;
    }
};
