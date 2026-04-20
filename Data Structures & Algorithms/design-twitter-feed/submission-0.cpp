class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweetMap; // {time, tweetId}
    unordered_map<int, unordered_set<int>> followMap;
    int timer = 0;
    priority_queue<pair<int, int>> pq;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        followMap[userId].insert(userId);
        priority_queue<tuple<int, int, int>> pq;
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                int idx = (int)tweetMap[followeeId].size() - 1;
                int time = tweetMap[followeeId][idx].first;
                pq.push({time, followeeId, idx});
            }
        }
        while (!pq.empty() && ans.size() < 10) {
            auto [time, uid, idx] = pq.top();
            pq.pop();

            ans.push_back(tweetMap[uid][idx].second);
            
            if (idx > 0) {
                int prevIdx = idx - 1;
                int prevTime = tweetMap[uid][prevIdx].first;
                pq.push({prevTime, uid, prevIdx});
            }
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};
