/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

https://www.interviewbit.com/problems/valid-sudoku/
*/

#define GRIDSIZE 9

bool isValid(const vector<string>& A, int row, int col)
{
    char elem = A[row][col]; 
    
    //check range
    if (elem - '0' < 1 || elem - '0' > 9)
        return false;
    
    //check for duplicates in row and col
    for (auto p = 0; p<GRIDSIZE; ++p)
    {
        if (A[p][col] == elem && p != row)  return false;
        if (A[row][p] == elem && p != col)  return false;
    }
    
    //check for duplicates in subgrids
    int subRow = (row/3)*3;
    int subCol = (col/3)*3;
    
    for (auto i = subRow; i<subRow+3; ++i)
    {
        for (auto j = subCol; j<subCol+3; ++j)
            if (A[i][j] == elem && (i != row || j != col))
                return false;
    }
    
    return 1;
}

int sudokuRunner(const vector<string>& A, int row, int col)
{
    if (row == 9)
        return 1;
    
    int nextRow, nextCol;
    if (col == 8)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    else
    {
        nextRow = row;
        nextCol = col + 1;
    }
    
    if (A[row][col] != '.')
    {
        if (!isValid(A, row, col))
            return 0;
    }
    
    return sudokuRunner(A, nextRow, nextCol);
}

int Solution::isValidSudoku(const vector<string> &A) {
    if (A.size() != GRIDSIZE || A[0].size() != GRIDSIZE)
        return 0;
    return sudokuRunner(A, 0, 0);
}
