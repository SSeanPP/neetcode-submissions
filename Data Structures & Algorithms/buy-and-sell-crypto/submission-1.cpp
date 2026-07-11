class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit{};
        int lowestSell{prices[0]};

        for(int i : prices) {
            if (i < lowestSell) {
                lowestSell = i;
            } else {
                maxProfit = std::max(maxProfit, (i - lowestSell));
            }
        }

        return maxProfit;
    }
};
