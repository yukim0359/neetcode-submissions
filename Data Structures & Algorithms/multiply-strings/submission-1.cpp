class Solution {
public:
    unsigned long long stringToInt(string& s) {
        unsigned long long ans = 0ull;
        for (int i = 0; i < s.size(); ++i) {
            ans *= 10;
            ans += s[i] - '0';
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        unsigned long long ansInt = stringToInt(num1) * stringToInt(num2);
        return to_string(ansInt);
    }
};
