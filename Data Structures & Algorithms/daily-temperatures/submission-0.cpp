class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                ret[idx] = i - idx;
            }
            st.push(i);
        }
        return ret;
    }
};
