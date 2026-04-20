class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;

        while (true) {
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
            while (numbers[l] + numbers[r] > target) r--;
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
            while (numbers[l] + numbers[r] < target) l++;
        }
    }
};
