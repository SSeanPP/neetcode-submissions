class Solution {
public:
    bool isPalindrome(string s) {
        return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
