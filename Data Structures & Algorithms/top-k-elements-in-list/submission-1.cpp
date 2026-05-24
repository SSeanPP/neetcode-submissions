#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyMap;
        frequencyMap.reserve(nums.size());

        for (const int& i : nums) {
            frequencyMap[i]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for (auto& [key, value] : frequencyMap) {
            buckets[value].push_back(key);
        }

        std::vector<int> returnVec;
        returnVec.reserve(k);
        for (auto& it : std::views::reverse(buckets)) {
            for(const int& i : std::views::reverse(it)) {
                returnVec.push_back(i);

                if(returnVec.size() == k) {
                    return returnVec;
                }
            }
        }

        return returnVec;
    }
};
