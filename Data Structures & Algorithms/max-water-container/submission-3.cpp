#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left{}, right{heights.size()-1}, maxSize{};
        
        while(left < right) {
            if(heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }

            maxSize = std::max(maxSize, 
                (std::min(heights[left], heights[right]) * (right - left))
            );
        }

        return static_cast<int>(maxSize);
    }

};
