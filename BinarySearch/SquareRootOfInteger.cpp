
/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

https://www.interviewbit.com/problems/square-root-of-integer/
*/

int Solution::sqrt(int A) {
    if (A==0 || A==1) return A;
    int start = 0, end = A;
    int ans;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if (mid <= A/mid) 
        {
            start = mid + 1;
            ans = mid;
        }
        else 
            end = mid - 1;
    }
    return ans;
}
