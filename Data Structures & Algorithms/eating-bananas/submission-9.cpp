class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        int k{piles[piles.size() - 1]}, left{1}, right{piles[piles.size() - 1]};
        int totalHours{}, eatingSpeed{};

        while (left <= right) {
            eatingSpeed = left + ((right - left)) / 2;
            totalHours = 0;
            for(size_t i{}; i < piles.size(); i++) {
                totalHours += (piles[i] + eatingSpeed - 1) / eatingSpeed; 
            }

            if (totalHours <= h) {
                k = eatingSpeed;
                right = eatingSpeed - 1;
            } else {
                left = eatingSpeed + 1;
            }
        }

        return k;
    }
};
