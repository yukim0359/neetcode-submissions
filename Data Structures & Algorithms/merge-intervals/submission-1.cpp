class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> res;

        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
