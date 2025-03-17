class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool firstRowZero = false, firstColZero = false;


        // Check if first row needs to be zero
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRowZero = true;

        // Check if first column needs to be zero
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstColZero = true;

            // Use first row and column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // Set rows to zero based on markers
        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                fill(matrix[i].begin(), matrix[i].end(), 0);

        // Set columns to zero based on markers
        for (int j = 1; j < n; j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;

        // Set first row to zero if needed
        if (firstRowZero)
            fill(matrix[0].begin(), matrix[0].end(), 0);

        // Set first column to zero if needed
        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
        
    
};