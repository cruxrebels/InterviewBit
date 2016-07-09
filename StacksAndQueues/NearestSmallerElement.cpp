/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10]
Return : [-1, 4, -1, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

https://www.interviewbit.com/problems/nearest-smaller-element/?ref=similar_problems
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> corresEle;
    int smallestInd = -1;
    for (auto i = 0; i<A.size(); ++i)
    {
        if (i==0 || A[smallestInd] > A[i])
        {
            corresEle.emplace_back(-1);
            smallestInd = i;
        }
        else 
        {
            for (auto j = i-1; j>smallestInd-1; --j)
            {
                if (A[j]==A[i])
                {
                    if (A[j] == A[smallestInd])
                    {
                        corresEle.emplace_back(-1);
                        break;
                    }
                    continue;   
                }
                else if (A[j]<A[i])
                {
                    corresEle.emplace_back(A[j]);
                    break;
                }
            }
            
        }
    }
    return corresEle;
}
