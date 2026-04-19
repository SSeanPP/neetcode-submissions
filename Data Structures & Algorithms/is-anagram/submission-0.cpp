class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sWord;
        unordered_map<char, int> tWord;

        for (char c : s) {
            sWord[c]++;
        }

        for (char c : t){
            tWord[c]++;
        }

        if (sWord == tWord) {
            return true;
        } else {
            return false;
        }
    }
};
