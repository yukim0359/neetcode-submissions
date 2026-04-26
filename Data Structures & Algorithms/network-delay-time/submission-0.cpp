class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& v : times) {
            graph[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [curTime, node] = pq.top();
            pq.pop();

            if (curTime > dist[node]) continue;

            for (auto [target, time] : graph[node]) {
                if (curTime + time < dist[target]) {
                    dist[target] = curTime + time;
                    pq.push({curTime + time, target});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
