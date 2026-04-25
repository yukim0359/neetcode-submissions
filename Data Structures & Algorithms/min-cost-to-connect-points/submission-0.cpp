class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        visited[0] = true;

        for (int i = 1; i < n; ++i) {
            auto& v = points[i];
            pq.push({v[0] + v[1], i});
        }

        int ans = 0;
        while (!pq.empty()) {
            auto [dist, idx] = pq.top();
            pq.pop();
            if (visited[idx]) continue;
            visited[idx] = true;
            ans += dist;
            for (int next = 0; next < n; ++next) {
                if (visited[next]) continue;
                pq.push({
                    abs(points[idx][0] - points[next][0]) + abs(points[idx][1] - points[next][1]),
                    next
                });
            }
        }
        return ans;
    }
};
