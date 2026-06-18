class Solution {
public:
    std::stack<int> vals;
    std::unordered_set<char> operators{'-', '+', '*', '/'};

    int evalRPN(vector<string>& tokens) {
        for (string s : tokens) {
            if(s.size() == 1 && operators.contains(s[0])) {
                int right{vals.top()};
                vals.pop();
                int left{vals.top()};
                vals.pop();

                if (s[0] == '-') {
                    vals.push((left - right));
                } else if (s[0] == '+') {
                    vals.push((left + right));
                } else if (s[0] == '*') {
                    vals.push((left * right));
                } else {
                    vals.push((left / right));
                }
            } else {
                vals.push(std::stoi(s));
            }
        }

        return vals.top();
    }
};
