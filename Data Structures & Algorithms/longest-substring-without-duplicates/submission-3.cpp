class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::size_t left{}, right{};
        int maxLength{};
        std::unordered_set<char> chars;

        for (char c : s) {
            while(chars.contains(c) && !chars.empty()) {
                chars.erase(s[left]);
                left++;
            }

            maxLength = std::max(static_cast<int>((right+1)-left), maxLength);
            chars.insert(c);
            right++;
        }

        return maxLength;
    }
};
