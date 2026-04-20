class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> count;
        for (int i : hand) {
            count[i]++;
        }

        sort(hand.begin(), hand.end());
        for (int x : hand) {
            if (count[x] == 0) continue;
            for (int i = x; i < x + groupSize; ++i) {
                if (count[i] == 0) return false;
                count[i]--;  
            }
        }

        return true;
    }
};
