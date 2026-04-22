class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> v = mp[key];
        int n = v.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid].first == timestamp) return v[mid].second;
            else if (v[mid].first < timestamp) l = mid + 1;
            else if (v[mid].first > timestamp) r = mid - 1;
        }

        return (r == -1) ? "" : v[r].second;
    }
};
