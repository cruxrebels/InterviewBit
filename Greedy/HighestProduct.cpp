/*
Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 
Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000

https://www.interviewbit.com/problems/highest-product/
*/

int Solution::maxp3(vector<int> &A) {
    auto size = A.size();
    sort(A.begin(), A.end());
    int allPositives = A[size-1]*A[size-2]*A[size-3];
    int twoNegatives = A[0]*A[1]*A[size-1];
    int res = max(allPositives, twoNegatives);
    return res;
}
