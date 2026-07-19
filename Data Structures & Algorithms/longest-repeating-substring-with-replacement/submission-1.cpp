class Solution {
public:
    int characterReplacement(string s, int k) {
        std::size_t left{}, right{};
        int maxLength{};
        std::unordered_map<char, int> chars;

        for (char c : s) {
            chars[c] += 1;

            while(chars.size() > 1 && minElement(chars) > k) {
                chars[s[left]] -= 1;
                if(chars[s[left]] <= 0) chars.erase(s[left]);
                left++;
            }

            maxLength = std::max(static_cast<int>((right+1)-left), maxLength);
            right++;
        }

        return maxLength; 
    }

    int minElement(const auto& mapView) {
        int total{}, largest{};

        for(const auto& [key, value] : mapView) {
            total += value;
            largest = std::max(largest, value);
        }

        return total-largest;
    }
};
