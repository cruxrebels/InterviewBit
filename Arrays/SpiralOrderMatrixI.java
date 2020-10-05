/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]

https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> spiralOrder(final List<ArrayList<Integer>> A) {
        ArrayList<Integer> result = new ArrayList();
        int rows = A.size();
        if (rows == 1) {
            result = A.get(0);
            return result;
        }
        
        int cols = A.get(0).size(), left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        int layer = 0;
        
        // Solution A
        /*
        int dir = 0, row = 0, col = 0;
        
        result.add(A.get(0).get(0));
        for (int i = 1; i < rows*cols; ++i) {
            switch (dir) {
                case 0:
                    if (col == cols - layer - 1) {
                        ++row;
                        dir = 1;
                    }  else 
                        ++col;
                    break;
                case 1:
                    if (row == rows - layer - 1) {
                        --col;
                        dir = 2;
                    }  else 
                        ++row;
                    break;
                case 2:
                    if (col == layer) {
                        --row;
                        dir = 3;
                    }  else 
                        --col;
                    break;
                case 3:
                    if (row == layer + 1) {
                        ++col;
                        dir = 0;
                        ++layer;
                    }  else 
                        --row;
                    break;
            }
            result.add(A.get(row).get(col));
        }
        */
        
        // Solution B - more straghtforward to understand
        while (left <= right && top <= bottom) {
            switch (layer) {
                case 0:
                    for (int j = left; j <= right; ++j) {
                        result.add(A.get(top).get(j));
                    }
                    ++top;
                    layer = 1;
                    break;
                case 1: 
                    for (int j = top; j <= bottom; ++j) {
                        result.add(A.get(j).get(right));
                    }
                    --right;
                    layer = 2;
                    break;
                case 2: 
                    for (int j = right; j >= left; --j) {
                        result.add(A.get(bottom).get(j));
                    }
                    --bottom;
                    layer = 3;
                    break;
                case 3: 
                    for (int j = bottom; j >= top; --j) {
                        result.add(A.get(j).get(left));
                    }
                    ++left;
                    layer = 0;
                    break;
                default:
                    break;
            }   
        }
        return result;
    }
}
