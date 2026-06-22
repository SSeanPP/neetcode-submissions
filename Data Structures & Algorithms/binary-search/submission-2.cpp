class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t left{}, right{nums.size()-1};
        size_t index{left + (right / 2)};

        while(nums[index] != target) {
            if(nums[index] < target) {
                left += (right-left) / 2;
            } else {
                right -= (right-left) / 2;
            }
            
            index = left + (right - left) / 2;
            if((index == 0 && nums[index] != target) || index == nums.size() && nums[index] != target) return -1;
        }

        return index;
    }
};
