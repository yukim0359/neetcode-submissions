class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all_prod = 1;
        int zero_count = 0;
        for (int n: nums){
            if (n == 0) zero_count++;
            else all_prod *= n;
        }
        vector<int> ret;
        for (int n: nums){
            if (zero_count >= 2) ret.push_back(0);
            else if (zero_count == 1){
                if (n == 0) ret.push_back(all_prod);
                else ret.push_back(0);
            }
            else ret.push_back(all_prod / n);
        }
        return ret;
    }
};
