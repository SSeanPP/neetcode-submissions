class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<size_t> stk{};
        std::vector<int> result(temperatures.size());
        
        for (size_t i{}; i < temperatures.size(); i++) {
            while(!stk.empty() && temperatures[i] >temperatures[stk.top()]) {
                result[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }
};
