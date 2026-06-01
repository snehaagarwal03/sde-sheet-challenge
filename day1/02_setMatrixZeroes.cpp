class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // vector to store the position of zeroes in the matrix 
        vector<vector<int>> zeroPositions;

        int rows = matrix.size();      // outer vector size gives row size
        int cols = matrix[0].size();   // inner vector size gives column size

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(matrix[i][j] == 0) {
                    zeroPositions.push_back({i, j});
                }

            }
        }

        for(int k = 0; k < zeroPositions.size(); k++) {

            int r = zeroPositions[k][0];
            int c = zeroPositions[k][1];

            // r gives the row position and through s we access columns 
            // as we move horizontally right
            for(int s = 0; s < cols; s++) {
                matrix[r][s] = 0;
            }

            // c gives the column position and through t we access rows 
            // as we moe vertically down
            for(int t = 0; t < rows; t++) {
                matrix[t][c] = 0;
            }
        }
        
    }
};