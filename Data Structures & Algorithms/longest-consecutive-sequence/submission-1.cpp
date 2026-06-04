class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> counter;
        for (int n : nums) {
            counter.insert(n);
        }

        int ret = 1;
        for (int n : nums) {
            if (counter.contains(n - 1)) continue;
            int length = 1;
            while (counter.contains(n + 1)) {
                n++;
                length++;
            }
            ret = max(ret, length);
        }

        return ret;
    }
};
