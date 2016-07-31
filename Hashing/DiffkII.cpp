/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.
See Expected Output

https://www.interviewbit.com/problems/diffk-ii/
*/

int Solution::diffPossible(const vector<int> &A, int B) {
    vector<int> input(A);
    sort(input.begin(), input.end());
    auto p = 0, q = 0;
    auto size = input.size();
    while (q < size)
    {
        if (p == q)
            ++q;
        else if (input[q]-input[p] == B && p!=q)
            return 1;
        else if (input[q]-input[p] < B)
            ++q;
        else if (input[q]-input[p] > B)
            ++p;
    }
    return 0;
}
