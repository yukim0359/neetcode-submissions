class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char c : tasks) {
            cnt[c - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int x : cnt) {
            if (x > 0) {
                maxHeap.push(x);
            }
        }

        queue<pair<int, int>> cooldown; 
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            if (maxHeap.empty()) {
                time = cooldown.front().second;
            } else {
                time++;
            }

            if (!maxHeap.empty()) {
                int remain = maxHeap.top();
                maxHeap.pop();
                remain--;

                if (remain > 0) {
                    cooldown.push({remain, time + n + 1});
                }
            }

            while (!cooldown.empty() && cooldown.front().second <= time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};