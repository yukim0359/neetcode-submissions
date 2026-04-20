class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int startIdx = 0;

    void dfs(vector<int>& nums) {
        ans.push_back(path);

        for (int i = startIdx; i < nums.size(); ++i) {
            startIdx = i + 1;
            path.push_back(nums[i]);
            dfs(nums);
            startIdx = i;
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums);
        return ans;
    }
};
