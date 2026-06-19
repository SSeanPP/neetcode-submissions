class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<size_t> stk{};
        std::vector<int> result(temperatures.size());
        
        for (size_t i{}; i < temperatures.size(); i++) {
            std::stack<std::pair<int,size_t>> inner{};
            while(!stk.empty() && temperatures[i] >temperatures[stk.top()]) {
                inner.push(std::pair(i-stk.top(), stk.top()));
                stk.pop();
            }

            while(!inner.empty()) {
                result[inner.top().second] = inner.top().first;
                inner.pop();
            }

            stk.push(i);
        }

        while(!stk.empty()) {
            result[stk.top()] = 0;
            stk.pop();
        }

        return result;
    }
};
