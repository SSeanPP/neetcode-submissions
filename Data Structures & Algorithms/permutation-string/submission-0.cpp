class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> s1Chars;
        std::unordered_map<char, int> windowChars;
        
        int left{};

        for (char c : s1) {
            s1Chars[c] += 1;
        }

        for(int right = 0; right < s1.size(); right++) {
            windowChars[s2[right]] += 1;
        }

        if(windowChars == s1Chars) return true;

        for(int right = s1.size(); right < s2.size(); right++) {
            windowChars[s2[left]] -= 1;
            if(windowChars[s2[left]] == 0) windowChars.erase(s2[left]);
            left++;
            
            windowChars[s2[right]] += 1;

            if(windowChars == s1Chars) return true;
        }

        return false;
    }
};
