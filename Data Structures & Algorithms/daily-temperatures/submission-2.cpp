class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(days, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < days; ++i) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                auto [temp, day] = st.top();
                st.pop();
                res[day] = i - day;
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};
