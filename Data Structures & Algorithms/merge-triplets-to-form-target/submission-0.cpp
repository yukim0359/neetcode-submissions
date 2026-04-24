class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> existSameValue(3, false);

        for (auto& v : triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) continue;
            if (v[0] == target[0]) existSameValue[0] = true;
            if (v[1] == target[1]) existSameValue[1] = true;
            if (v[2] == target[2]) existSameValue[2] = true;
        }

        return existSameValue[0] && existSameValue[1] && existSameValue[2];
    }
};
