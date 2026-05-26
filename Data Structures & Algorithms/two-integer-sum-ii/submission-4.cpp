class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0, rightPointer = numbers.size() -1;

        while(leftPointer < rightPointer){
            int currResults = numbers[leftPointer]+numbers[rightPointer];
            if (currResults==target){
                return {leftPointer+1, rightPointer+1};
            } else if(currResults < target){
                leftPointer++;
            } else {
                rightPointer--;
            }
        }

        return {};
    }
};
