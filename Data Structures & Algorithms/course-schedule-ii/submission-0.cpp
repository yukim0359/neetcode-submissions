class Solution {
public:
    vector<int> ans;

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state) {
        if (state[course] == 1) return false;
        if (state[course] == 2) return true;

        state[course] = 1;
        ans.push_back(course);

        for (int next : graph[course]) {
            if (!dfs(next, graph, state)) return false;
        }

        state[course] = 2;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (auto v : prerequisites) {
            int e = v[0], s = v[1];
            graph[e].push_back(s);
            inDeg[s]++;
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0) {
                if (!dfs(i, graph, state)) return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
