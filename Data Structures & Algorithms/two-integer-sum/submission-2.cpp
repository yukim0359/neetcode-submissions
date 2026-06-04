class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdx;
        for (int i = 0; i < nums.size(); ++i) {
            if (numToIdx.contains(target - nums[i])) {
                return {numToIdx[target - nums[i]], i};
            }
            numToIdx[nums[i]] = i;
        }
        return {};
    }
};
