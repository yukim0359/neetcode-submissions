class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (int i = 0; i < n; ++i) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (cnt1 == cnt2) return true;

        for (int r = n; r < m; ++r) {
            int l = r - n;

            cnt2[s2[l] - 'a']--;
            cnt2[s2[r] - 'a']++;

            if (cnt1 == cnt2) return true;
        }

        return false;
    }
};
