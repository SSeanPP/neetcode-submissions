class Solution {
public:
    int findMin(vector<int> &nums) {
        int left{}, right{static_cast<int>(nums.size())-1};
        int mid{right / 2};

        while(left < right) {
            mid = ((right-left) / 2) + left;

            if (nums[mid] < nums [right]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        return nums[left];
    }
};
