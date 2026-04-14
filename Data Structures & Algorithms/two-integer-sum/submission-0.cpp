class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i=0; i<nums.size(); ++i){
            if (mp.contains(target - nums[i])){
                vector<int> ans;
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        vector<int> ans;
        return ans;
    }
};
