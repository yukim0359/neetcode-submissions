class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);

        pq.push({0, 0});
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
