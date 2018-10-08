/*
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

https://www.interviewbit.com/problems/prettyprint/
*/

vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int>> matrix(A+A-1, vector<int>(A+A-1, 1));
    int temp = A, inner = 0, outer = A+A-2, col = 0, endCol = A+A-1;
    for (auto i = 0; i < A-1; ++i) {
        for (auto j = col; j < endCol; ++j) {
            for (auto k = col; k < endCol; ++k) {
                if (j == col || j == endCol-1) {
                    matrix[j][k] = temp;
                }
                else {
                    matrix[j][inner] = temp;
                    matrix[j][outer] = temp;
                }
            }
        }
        ++inner; ++col;
        --outer; --endCol;
        --temp;
    }
    return matrix;
}
