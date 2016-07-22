/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

https://www.interviewbit.com/problems/sudoku/
*/

const int N = 9;

bool isValid(vector<vector<char> > &A, int row, int col)
{
    char elem = A[row][col];
    
    //check range
    if (elem - '0' < 1 || elem - '0' > 9)
        return false;
        
    //check row and column for duplicates
    for (auto p = 0; p<N; ++p)
    {
        if (A[p][col] == elem && p != row)
            return false;
        if (A[row][p] == elem && p != col)
            return false;
    }
    
    //check 3x3 subgrid for duplicates
    int subRow = (row/3)*3; //Ex: row = 2 belongs to first subgrid, so to bring back row to index 0
    int subCol = (col/3)*3; //so as to start iterating first subgrid, we do 2/3 = 0 then 0*3 = 0.
    
    for (auto i = subRow; i<subRow+3; ++i)
    {
        for (auto j = subCol; j<subCol+3; ++j)
        {
            if (A[i][j] == elem && (i != row || j != col))
                return false;
        }
    }
    
    return true;
}

bool sudoku(vector<vector<char> > &A, int row, int col)
{
    if (row == 9)
        return true;
        
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
            return false;
        return sudoku(A, nextRow, nextCol);
    }
    
    for (auto i = 1; i<=N; ++i)
    {
        A[row][col] = i + '0';
        if (isValid(A, row, col) && sudoku(A, nextRow, nextCol))
            return true;
    }
    
    A[row][col] = '.';
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    if (A.size() != N || A[0].size() != N)
        return;
    sudoku(A, 0, 0);
}
