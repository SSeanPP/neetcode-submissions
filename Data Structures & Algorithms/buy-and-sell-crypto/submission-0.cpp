class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit{};
        for(int i{static_cast<int>(prices.size()) - 1}; i >= 0; i--) {
            for(int j{i-1}; j >= 0; j--) {
                maxProfit = std::max((maxProfit),(prices[i]-prices[j]));
            }   
        }

        return maxProfit;
    }
};
