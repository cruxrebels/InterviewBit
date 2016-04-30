/*Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
* All elements in the array are in the range [0, N-1]
* N * N does not overflow for a signed integer 

https://www.interviewbit.com/problems/rearrange-array/ */
void Solution::arrange(vector<int> &A) {
    auto n = A.size();
    for(auto i=0; i<n; ++i)
    {
        A[i] += (A[A[i]]%n)*n;
    }
    for(auto i=0; i<n; ++i)
    {
       A[i] /= n;
    }
}
