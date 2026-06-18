class MinStack {
public:
    std::stack<int> stk;
    std::stack<int> minStk;

    MinStack() :
        stk{},
        minStk{}
        {

    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(val);
            minStk.push(val);
        } else {
            int minTop{minStk.top()};

            if (minTop > val) {
                minStk.push(val);
            } else {
                minStk.push(minTop);
            }

            stk.push(val);
        }

        
    }
    
    void pop() {
        if (stk.empty()) return;
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
