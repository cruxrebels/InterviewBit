/*
Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= N <= 3000
1 <= A[i] <= 1e7
Example:

Input 1:
    A = [1, 2, 1]
Output 1:
    3
Explanation 1:
    [1, 2, 1] is the longest subsequence.


Input 2:
    [1, 11, 2, 10, 4, 5, 2, 1]
Output 2:
    6
Explanation 2:
    [1 2 10 4 2 1] is the longest subsequence.

https://www.interviewbit.com/problems/length-of-longest-subsequence/
*/    

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if( n == 0 )
    {
        return 0;
    }
    int lis[n]; 
    for (auto i = 0; i < n; ++i)
    {
        lis[i] = 1; 
    }
    for (auto i = 1; i < n; ++i)
    { 
        for (auto j = 0; j < i; ++j)
        {
            if (A[i] > A[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1; 
        }    
    }
    int lds[n]; 
    for (auto i = 0; i < n; ++i) 
    {
        lds[i] = 1; 
    }
    for (auto i = n-2; i >= 0; --i) 
    {   for (auto j = n-1; j > i; --j) 
        {
            if (A[i] > A[j] && lds[i] < lds[j] + 1) 
                lds[i] = lds[j] + 1; 
        }
    }
    int max = lis[0] + lds[0] - 1; 
    for (auto i = 1; i < n; ++i){
        if (lis[i] + lds[i] - 1 > max) 
            max = lis[i] + lds[i] - 1;
    }
    return max; 
} 
