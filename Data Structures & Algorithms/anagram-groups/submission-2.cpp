class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, std::vector<string>> masterRecord;

        for(string str : strs) {
            std::map<char, int> charFreq;
            for(char c : str) {
                charFreq[c]++;
            }

            masterRecord[charFreq].push_back(str);
        }

        vector<vector<string>> result;

        for(auto& it : masterRecord) {
            vector<string> factor;
            for (string str : it.second) {
                factor.push_back(std::move(str));
            }

            result.push_back(std::move(factor));
        }

        return result;
    }
};
