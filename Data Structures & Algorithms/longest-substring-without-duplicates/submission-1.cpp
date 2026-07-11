class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> subChar;
        int length{1};

        for(char c : s) {
            if (subChar.contains(c)) {
                length = std::max(length, static_cast<int>(subChar.size()));
                subChar.clear();  
            } 

            subChar.insert(c);
        }

        return length;
    }
};
