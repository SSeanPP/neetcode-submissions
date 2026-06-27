class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        int total{std::accumulate(piles.begin(), piles.end(), 0)};
        int k{piles[piles.size() - 1]}, left{1}, right{static_cast<int>(piles.size() - 1)}, mid{};
        size_t totalBites{}, eatingSpeed{};

        while (left <= right) {
            mid = left + ((right - left)) / 2;
            eatingSpeed = mid;
            totalBites = 0;
            for(size_t i{}; i < piles.size(); i++) {
                totalBites += (piles[i] + eatingSpeed - 1) / eatingSpeed; 
            }

            if (totalBites <= h) {
                k = eatingSpeed;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return k;
    }
};
