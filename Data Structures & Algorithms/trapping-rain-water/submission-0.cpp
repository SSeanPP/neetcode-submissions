class Solution {
public:
    int trap(vector<int>& height) {
        size_t left{}, right{}, occupied{}, volume{};
        while(right < height.size()) {
            left = right;
            occupied = 0;
            while (right < height.size() && height[right] < height[left]) {
                occupied += height[right];
                right++;        
            }

            if (height[left] < height[right]) {
                volume += (std::min(height[left],height[right]) * (right - left)) - occupied;
            }
        }

        return static_cast<int>(volume);
    }
};
