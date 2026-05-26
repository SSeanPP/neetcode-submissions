class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0, rightPointer = numbers.size() -1;
     
        int currResults;

        while(leftPointer < rightPointer){
            currResults = numbers[leftPointer]+numbers[rightPointer];
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
