class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        int i = 0;
        while (i <= n - 2) {
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (true) {
                        left++;
                        if (nums[left - 1] != nums[left] || left >= right) break;
                    }
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
            while (true) {
                i++;
                if (nums[i - 1] != nums[i] || i >= n - 2) break;
            }
        }
        return ret;
    }
};
