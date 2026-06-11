class Solution {
public:
    int trap(vector<int>& height) {
        size_t left{}, right{}, occupied{}, volume{};
        while(right < height.size()) {            
            if (height[left] <= height[right]) {
                volume += (std::min(height[left],height[right]) * (right - left - 1)) - occupied;
                left = right;
                occupied = 0;
            } else {
                occupied += height[right];
            }
            right++;
        }

        return static_cast<int>(volume);
    }
};
