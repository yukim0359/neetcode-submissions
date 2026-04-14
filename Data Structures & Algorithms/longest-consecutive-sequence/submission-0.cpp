class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n: nums) {
            st.insert(n);
        }
        int ret = 0;
        for(int n: nums) {
            if (st.contains(n - 1)) continue;
            int seq = 1;
            while (true) {
                if (st.contains(n + seq)) seq++;
                else break;
            }
            ret = max(ret, seq);
        }
        return ret;
    }
};
