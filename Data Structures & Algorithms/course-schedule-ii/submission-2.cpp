class Solution {
public:
    vector<int> ans;

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state) {
        if (state[course] == 1) return false;
        if (state[course] == 2) return true;

        state[course] = 1;

        for (int next : graph[course]) {
            if (!dfs(next, graph, state)) return false;
        }

        ans.push_back(course);
        state[course] = 2;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (auto& v : prerequisites) {
            int after = v[0], before = v[1];
            graph[after].push_back(before);
            inDeg[before]++;
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0) {
                if (!dfs(i, graph, state)) return {};
            }
        }

        return ans;
    }
};
