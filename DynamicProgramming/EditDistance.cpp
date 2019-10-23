/*
Given two strings A and B, 
Find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450


Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
    
    
https://www.interviewbit.com/problems/edit-distance/
*/

int Solution::minDistance(string A, string B) {
    int m = A.size(), n = B.size();
    int sol[m+1][n+1];
    for(auto i=0; i<=m; ++i){
        for(auto j=0; j<=n; ++j){
            if( i == 0 )
                sol[i][j] = j;
            else if( j == 0 )
                sol[i][j] = i;
            else if( A[i-1] == B[j-1] )
                sol[i][j] = sol[i-1][j-1];
            else
                sol[i][j] = 1 + min( sol[i][j-1], min( sol[i-1][j], sol[i-1][j-1]));
        }
    }
    return sol[m][n];
}
