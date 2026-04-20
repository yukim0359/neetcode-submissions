class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int cur_idx, int sum, int target) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        if (sum > target) return;

        for (int i = cur_idx; i < candidates.size(); ++i) {
            if (i > cur_idx && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], target);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        return ans;
    }
};
