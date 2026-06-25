class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t m{matrix.size()}, n{matrix[0].size()};
        size_t left{}, right{(m*n)-1};
        size_t mid{}, resultant{};

        while (left <= right) {
            mid = left + (right - left) / 2;
            resultant = matrix[std::min(((mid / m) - 1), 0)][mid % n];
            if (resultant == target) return true;
            else if (resultant < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
