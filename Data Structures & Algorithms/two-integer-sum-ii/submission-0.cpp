class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPointer = 0, rightPointer = numbers.size() -1;
        vector<int> results;

        while(leftPointer < rightPointer){
            int currResults = numbers[leftPointer]+numbers[rightPointer];
            if (currResults==target){
                results.push_back(leftPointer+1); results.push_back(rightPointer+1); return results;
            } else if(currResults < target){
                leftPointer++;
            } else {
                rightPointer--;
            }
        }

        return results;
    }
};
