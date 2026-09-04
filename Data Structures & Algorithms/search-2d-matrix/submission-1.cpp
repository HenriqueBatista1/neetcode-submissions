class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int M = matrix.size();
        int N = matrix[0].size();
        int left = 0;
        int right = (M * N) - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[mid / N][mid % N] == target) {
                return true;
            }

            if (matrix[mid / N][mid % N] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
