class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> triplets;
        std::sort(nums.begin(), nums.end());

        for(int target = 0; target < nums.size(); target++) {
            int leftPointer = 0, rightPointer = nums.size() - 1;
            
            while(leftPointer < target && rightPointer > target) {
                int currValue = nums[leftPointer]+nums[rightPointer]+nums[target];
                if(currValue==0) {
                    triplets.insert({nums[leftPointer], nums[target], nums[rightPointer]});
                    rightPointer--;
                    leftPointer++;
                } else if (currValue > 0) {
                    rightPointer--;
                } else {
                    leftPointer++;
                }
            }
        }

        return{triplets.begin(), triplets.end()};
    }
};
