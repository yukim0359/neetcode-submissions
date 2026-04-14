class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            ret = max(ret, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return ret;
    }
};
