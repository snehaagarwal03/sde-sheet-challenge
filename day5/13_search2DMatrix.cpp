class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;

        // we are using binary search considering the matrix as 1D array as all rows are sorted individually as well as collectively
        while(low <= high) {
            int mid = low + (high - low) / 2;
            // need to find the index of that mid value in the matrix
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;     
    }
};