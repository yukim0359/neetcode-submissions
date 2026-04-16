/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> starts, ends;
        starts.reserve(n);
        ends.reserve(n);

        for (const auto& interval : intervals) {
            starts.push_back(interval->start);
            ends.push_back(interval->end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        int rooms = 0;
        int ans = 0;

        while (s < n) {
            if (starts[s] < ends[e]) {
                rooms++;
                ans = max(ans, rooms);
                s++;
            } else {
                rooms--;
                e++;
            }
        }

        return ans;
    }
};
