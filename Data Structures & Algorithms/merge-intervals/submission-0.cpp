class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto compare = [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), compare);

        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ret;

        while (i < n) {
            while (i < n - 1 && intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
                i++;
            }
            ret.push_back(intervals[i]);
            i++;
        }
        return ret;
    }
};
