#include <array>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        array<int, 2001> counts = {};
        // for (int i=0; i<2001; i++) counts[i] = 0;
        for (int i: nums) counts[i + 1000]++;
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<2001; i++) {
            pq.push({counts[i], i - 1000});
        }
        vector<int> ans;
        for (int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
