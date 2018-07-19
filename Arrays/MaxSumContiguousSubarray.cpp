/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/

int Solution::maxSubArray(const vector<int> &A) {
    int maxSum = INT_MIN;
    int tempSum = 0;
    for (auto i = 0; i<A.size(); ++i)
    {
        tempSum += A[i];
        maxSum = max(maxSum, tempSum);
        if (tempSum < 0)
            tempSum = 0;
    }
    return maxSum;
}
