class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> elements{
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        std::stack<char> stk{};

        for(char c : s) {
            if(elements.contains(c)) {
                stk.push(c);
            } else {
                if(!stk.empty() && c != elements.at(stk.top())) return false;
                if(!stk.empty()) stk.pop();
            }
        }

        return true;

    }
};
