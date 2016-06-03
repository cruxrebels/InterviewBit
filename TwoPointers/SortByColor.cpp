/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

https://www.interviewbit.com/problems/sory-by-color/
*/

int twoPass(vector<int> &A, int n, int num)
{
    int i = 0, j = n-1;
    while(i<j)
    {
        if(A[j]==num)
            --j;
        else if(A[i]==num)
        {
            swap(A[i], A[j]);
            --j; ++i;
        }
        else 
            ++i;
    }
    for(auto p = 0; p<n; ++p)
        if(A[p]==num)
            return p;
    return n;
}
void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int newSize = twoPass(A, n, 2); 
    twoPass(A, newSize, 1);
}
