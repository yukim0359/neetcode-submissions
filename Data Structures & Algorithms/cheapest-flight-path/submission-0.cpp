class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& v : flights) {
            graph[v[0]].push_back({v[1], v[2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> cheapest(n, INT_MAX);
        cheapest[src] = 0;

        for (int i = 0; i <= k; ++i) {
            int sz = q.size();
            for (int j = 0; j < sz; ++j) {
                auto [node, curPrice] = q.front();
                q.pop();
                for (auto [next, price] : graph[node]) {
                    if (curPrice + price < cheapest[next]) {
                        cheapest[next] = curPrice + price;
                        q.push({next, curPrice + price});
                    }
                }
            }
        }
        return (cheapest[dst] != INT_MAX) ? cheapest[dst] : -1;
    }
};
