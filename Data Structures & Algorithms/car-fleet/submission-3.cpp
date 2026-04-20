class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        double prev_time = 0.0;
        int ans = 0;
        for (auto& [pos, speed] : cars) {
            double cur_time = (double)(target - pos) / speed;
            if (cur_time <= prev_time) {
                continue;
            } else {
                prev_time = cur_time;
                ans++;
            }
        }
        return ans;
    }
};
