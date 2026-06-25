class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m{static_cast<int>(matrix.size())}, n{static_cast<int>(matrix[0].size())};
        int left{}, right{(m*n) - 1};
        int mid{}, resultant{};

        while (left <= right) {
            mid = left + (right - left) / 2;
            resultant = matrix[mid / n][mid % n];
            if (resultant == target) return true;
            else if (resultant < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
