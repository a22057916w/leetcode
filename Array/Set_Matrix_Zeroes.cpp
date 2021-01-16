class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        // we don't sweep the first row and column, so we need to record the first entry of the matrix.
        // we can use matrix[0][0] to decide whether to set the first row to zero.
        // And, set a variable(like "isCol") to decide whether to set the first col to zero.
        bool isCol = false;


        for(int i = 0; i < row; i++) {

            // check if there is a zero in first column
            if(matrix[i][0] == 0)
                isCol = true;

            // sweep the rows from 2nd column
            for(int j = 1; j < col; j++)
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        // update the marked cols and rows to zero
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // see if the first row needs to be set to zero
        if(matrix[0][0] == 0)
            for(int i = 0; i < col; i++)
                matrix[0][i] = 0;


        // see if the first col needs to be set to zero
        if(isCol)
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
    }
};
