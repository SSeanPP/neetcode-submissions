class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t index{nums.size() / 2};
        while(nums[index] != target) {
            if(nums[index] > target) {
                index += index / 2;
            } else {
                index -= index /2;
            }

            if((index == 0 && nums[index] != target) || index == nums.size() && nums[index] != target) return -1;
        }

        return index;
    }
};
