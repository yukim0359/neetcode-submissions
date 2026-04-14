class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        vector<int> left_arr(nums.begin(), nums.begin() + l);
        auto it = lower_bound(left_arr.begin(), left_arr.end(), target);
        if (it != left_arr.end() && *it == target) {
            return it - left_arr.begin();   
        }
        vector<int> right_arr(nums.begin() + l, nums.end());
        it = lower_bound(right_arr.begin(), right_arr.end(), target);
        if (it != right_arr.end() && *it == target) {
            return l + it - right_arr.begin();
        }
        return -1;
    }
};
