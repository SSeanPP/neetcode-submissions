class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement{*std::max_element(piles.begin(), piles.end())};
        int k{maxElement}, left{1}, right{maxElement}, mid{};
        int totalHours{}, eatingSpeed{};

        while (left <= right) {
            mid = left + ((right - left)) / 2;
            eatingSpeed = mid;
            totalHours = 0;
            for(int pile : piles) {
                totalHours += (pile + eatingSpeed - 1) / eatingSpeed; 
            }

            if (totalHours <= h) {
                k = eatingSpeed;
                
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return k;
    }
};
