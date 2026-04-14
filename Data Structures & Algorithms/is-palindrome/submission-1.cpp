class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (!is_alphanumeric(s[left])) left++;
        while (!is_alphanumeric(s[right])) right--;
        bool ret = true;
        while (left < right){
            if (tolower(s[left]) != tolower(s[right])) {
                ret = false;
                break;
            }
            left++;
            right--;
            while (!is_alphanumeric(s[left])) left++;
            while (!is_alphanumeric(s[right])) right--;
        }
        return ret;
    }
private:
    bool is_alphanumeric (char ch){
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        else return false;
    }
};
