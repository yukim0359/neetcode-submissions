class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
        ans.push_back(pq.top());

        for (int r = k; r < nums.size(); ++r) {
            int l = r - k;
            mp[nums[r]]++;
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) mp.erase(nums[l]);
            if (mp[nums[r]] == 1) pq.push(nums[r]);
            while (true) {
                int tmp = pq.top();
                if (mp.contains(tmp)) {
                    ans.push_back(tmp);
                    break;
                }
                pq.pop();
            }
        }

        return ans;
    }
};
