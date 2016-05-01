/*
A robot is located at the top-left corner of an A x B grid.

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
https://www.interviewbit.com/problems/grid-unique-paths/
*/

/*int fact(int x)
{
    return x<2 ? x : x*fact(x-1);
}*/
int Solution::uniquePaths(int A, int B) {
    //Combinotrics approach (simple implementation) - (m-1 + n-1)!/((m-1)!(n-1)!)
    /*if(A<=1 || B<=1)
        return 1;
    size_t fa = fact(A-1);
    //cout << fa << " ";
    size_t fb = fact(B-1);
    //cout << fb << " ";
    size_t top = fact(A+B-2);
    //cout << top << " ";
    size_t bot = fa*fb;
    return (size_t)(top/bot);*/
    
    //Combinotrics approach (difficult implementation)
    /*long long ans = 1;
    for (int i = B; i < (A + B - 1); i++) {
        ans *= i;
        ans /= (i - B + 1);
    }
    return (int)ans;*/
    
    //Dynamic Programming approach (very elegant & simple)
    int ways[A][B];
    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < B; ++j)
        {
            if(i == 0 && j == 0)
                ways[i][j] = 1;
            else if(i == 0)
                ways[i][j] = ways[i][j-1];
            else if(j == 0)
                ways[i][j] = ways[i-1][j];
            else
                ways[i][j] = ways[i-1][j] + ways[i][j-1];
        }
    }
    return ways[A-1][B-1];
}
