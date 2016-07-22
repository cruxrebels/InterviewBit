/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen 
and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

https://www.interviewbit.com/problems/nqueens/
*/

bool isSafe(vector<vector<string> >& board, int row, int col, int N)
{
    //check left side rows
    for (auto j = 0; j<col; ++j)
        if (board[row][j] == "Q")
            return false;
    
    //check top left side diagonal
    for (auto i = row, j = col; i>-1 && j>-1; --i, --j)
        if (board[i][j] == "Q")
            return false;
            
    //check bottom left side diagonal
    for (auto i = row, j = col; i<N && j>-1; ++i, --j)
        if (board[i][j] == "Q")
            return false;
    
    return true;
}
bool backtracking(vector<vector<string> >& board, int col, vector<vector<string> >& testboard, int N)
{
    if (col == N)
    {
        vector<string> emptyRow;
        board.emplace_back(emptyRow);
        int size = board.size();
        
        for (auto i = 0; i<N; ++i)
        {
            string row = "";
            for (auto j = 0; j<N; ++j)
                row += testboard[i][j];
            
            board[size-1].emplace_back(row);
        }
        return false;
    }
    
    for (auto i = 0; i<N; ++i)
    {
        if (isSafe(testboard, i, col, N))
        {
            testboard[i][col] = "Q";
            
            if (!backtracking(board, col+1, testboard, N))
                testboard[i][col] = ".";
            else
                return true;
        }
    }
    return false;
}
vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > testboard;
    
    if (A==2 || A==3)
        return testboard;
    
    vector<string> row(A, ".");
    
    for (auto i = 0; i<A; ++i)
        testboard.emplace_back(row);
    
    vector<vector<string> > board;
    backtracking(board, 0, testboard, A);
    return board;
}
