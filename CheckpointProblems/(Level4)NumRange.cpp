/*
Given an array of non negative integers A, and a range (B, C), 
find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C

Continuous subsequence is defined as all the numbers A[i], A[i + 1], .... A[j]
where 0 <= i <= j < size(A)

Example :

A : [10, 5, 1, 0, 2]
(B, C) : (6, 8)
ans = 3 
as [5, 1], [5, 1, 0], [5, 1, 0, 2] are the only 3 continuous subsequence with their sum in the range [6, 8]

 NOTE : The answer is guranteed to fit in a 32 bit signed integer. 
 
https://www.interviewbit.com/problems/numrange/
*/

// Bruteforce O(N^2) solution
int Solution::numRange(vector<int> &A, int B, int C) {
    int count = 0; 
    for (size_t i = 0; i < A.size(); ++i) {
        int sum = 0;
        for (size_t j = i; j < A.size(); ++j) {
            sum += A[j];
            if (sum >= B && sum <= C)
                ++count;
            else if (sum > C)
                break;
        }
    }
    return count;
}
