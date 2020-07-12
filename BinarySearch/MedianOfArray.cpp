/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3

 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

https://www.interviewbit.com/problems/median-of-array/

*/

double medianInOneArray(const vector<int> &Arr)
{
    return (Arr.size() % 2 == 0)? (Arr[ Arr.size() / 2 ] + Arr[ Arr.size() / 2 - 1 ]) / 2.0: Arr[ Arr.size() / 2 ];
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    if(A.empty())
        return  medianInOneArray(B);
    if(B.empty())
        return medianInOneArray(A);
    if(A.size() > B.size())
        return findMedianSortedArrays(B,A);
    int n = A.size(), m = B.size();
    int start = 0, end = n, partitionX, partitionY, maxLeftX, maxLeftY, minRightX, minRightY;
    while(start <= end)
    {
        partitionX = (start + end) / 2;
        partitionY = (n + m + 1) / 2 - partitionX;
        
        maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
        maxLeftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
        minRightX = (partitionX == n) ? INT_MAX : A[partitionX];
        minRightY = (partitionX == m) ? INT_MAX : B[partitionY];
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            //found
            if((n + m) % 2 == 0)
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            return (double) max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY)
            end = partitionX - 1;
        else
            start = partitionX + 1;
    }
}

