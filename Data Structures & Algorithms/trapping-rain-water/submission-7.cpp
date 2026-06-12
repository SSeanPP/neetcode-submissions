class Solution {
public:
    int trap(vector<int>& height) {
        size_t left{}, right{height.size() - 1 }, maxLeft{}, maxRight{height.size() - 1 }, volume{};
        
        while(left < right) {
            if(height[left] < height[right]) {
                left++;

                if(height[left] > height[maxLeft]) {
                    maxLeft = left;
                } else {
                    volume += height[maxLeft] - height[left];
                }
            } else {
                right--;

                if(height[right] > height[maxRight]) {
                    maxRight = right;
                } else {
                    volume += height[maxRight] - height[right];
                }
            }
        }

        return (volume);
    }
};
