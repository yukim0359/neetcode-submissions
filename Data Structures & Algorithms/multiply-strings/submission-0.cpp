class Solution {
public:
    int stringToInt(string& s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans *= 10;
            ans += s[i] - '0';
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        int ansInt = stringToInt(num1) * stringToInt(num2);
        return to_string(ansInt);
    }
};
