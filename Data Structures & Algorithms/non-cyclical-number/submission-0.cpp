class Solution {
public:
    int squareSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += pow(n % 10, 2);
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            n = squareSum(n);
            if (n == 1) return true;
            if (st.contains(n)) return false;
            st.insert(n);
        }
    }
};
