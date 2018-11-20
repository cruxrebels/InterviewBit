/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem

See Expected Output

https://www.interviewbit.com/problems/matrix-search/
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    size_t rows = A.size();
    size_t cols = A[0].size();
    int start = 0, end = (rows*cols)-1;
    while (start <= end) {
        int mid = start + (end-start)/2;
        int row = mid/cols, col = mid%cols;
        if (A[row][col] == B)
            return 1;
        else if (A[row][col] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}
