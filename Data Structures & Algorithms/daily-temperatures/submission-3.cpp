class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(days, 0);
        stack<int> st;
        for (int i = 0; i < days; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int day = st.top();
                st.pop();
                res[day] = i - day;
            }
            st.push(i);
        }
        return res;
    }
};
