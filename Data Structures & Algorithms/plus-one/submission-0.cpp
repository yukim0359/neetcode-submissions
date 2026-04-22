class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans = digits;

        for (int i = n - 1; i >= 0; --i) {
            int s = ans[i] + carry;
            ans[i] = s % 10;
            carry = s / 10;
        }

        if (carry == 1) ans.insert(ans.begin(), carry);
        return ans;
    }
};
