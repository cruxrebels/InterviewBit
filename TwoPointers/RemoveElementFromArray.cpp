/*
Remove Element

Given an array and a value, remove all the instances of that value in the array. 
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

 Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1, 
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity.

https://www.interviewbit.com/problems/remove-element-from-array/
*/

int Solution::removeElement(vector<int> &A, int B) {
    auto n = A.size();
    auto count = 0;
    for (auto i = 0; i<n; ++i)
    {
        if(A[i]==B) continue;
        else
            A[count++] = A[i];
    }
    return count;
}
