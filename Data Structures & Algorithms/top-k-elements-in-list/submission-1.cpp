class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countFreq;
        for (int n : nums) countFreq[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [key, count] : countFreq) {
            pq.push({count, key});
            if (pq.size() > k) pq.pop();
        }

        vector<int> topK;
        for (int i = 0; i < k; ++i) {
            auto [count, key] = pq.top();
            pq.pop();
            topK.push_back(key);
        }

        return topK;
    }
};
