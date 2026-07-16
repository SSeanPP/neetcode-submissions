class Solution {
public:
    int findMin(vector<int> &nums) {
        int left{}, right{static_cast<int>(nums.size())-1};
        int mid{right / 2};

        while(nums[right] < nums[left]) {
            mid = ((right - left) / 2) + left;
            left = mid;
        }

        return nums[mid];
    }
};
