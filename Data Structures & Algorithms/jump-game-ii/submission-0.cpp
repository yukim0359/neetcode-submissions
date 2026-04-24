class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 1;
        int l = 0, r = 0;
        int n = nums.size();
        while (true) {
            int farthest = l;
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]);
            }
            if (farthest >= n - 1) return count;
            count++;
            l = r + 1, r = farthest;
        }
    }
};
