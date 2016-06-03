/*
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), 
 assume that elements that appear more than once in both arrays should be included multiple times in the final output.
 
 https://www.interviewbit.com/problems/intersection-of-sorted-arrays/
 */
 
 vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int p = 0, q = 0;
    vector<int> result;
    
    while(p<A.size() && q<B.size())
    {
        if(A[p]==B[q])
        {
            result.push_back(A[p]);
            ++p; ++q;
        }
        else if(A[p]<B[q])
            ++p;
        else
            ++q;
    }
    return result;
}
