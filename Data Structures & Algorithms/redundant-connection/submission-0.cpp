class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> st;
        int n = edges.size();

        for (int i = 0; i < n; ++i) {
            if (st.contains(edges[i][0]) && st.contains(edges[i][1])) {
                return edges[i];
            }
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
        }

        return {};
    }
};
