#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left{}, right{heights.size()-1};
        int maxSize{};
        do {
            maxSize = std::max(maxSize, returnArea((right-left), heights[left], heights[right]));
            left++;
            maxSize = std::max(maxSize, returnArea((right-left), heights[left], heights[right]));
            right--;
        } while (left < right);

        return maxSize;
    }

    int returnArea(int distance, int leftHeight, int rightHeight) {
        return distance * std::min(leftHeight, rightHeight);
    }
};
