class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> subChar;
        int length{};

        for(char c : s) {
            if (subChar.contains(c)) {
                length = subChar.size();
                subChar.clear();  
            } 

            subChar.insert(c);
        }

        return length;
    }
};
