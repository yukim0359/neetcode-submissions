class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charToRecentIdx;
        int longestLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (charToRecentIdx.contains(c)) {
                left = max(left, charToRecentIdx[c] + 1);
            }
            charToRecentIdx[c] = right;
            longestLength = max(longestLength, right - left + 1);
        }

        return longestLength;
    }
};
