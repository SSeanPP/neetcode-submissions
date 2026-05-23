class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> values;

        for (int i = 0; i < nums.size(); i++) {
            int residual = target - nums[i];
            if(auto it = values.find(residual); it != values.end()) {
                return vector<int> {it->second,i};
            }
            values[nums[i]] = i;
        }

        return vector<int>();
    }
};
