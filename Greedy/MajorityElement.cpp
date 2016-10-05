/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

https://www.interviewbit.com/problems/majority-element/
*/

int Solution::majorityElement(const vector<int> &A) {
    // Moore’s Voting Algorithm
    int majorityIndex = 0;
    for (int count = 1, i = 1; i<A.size(); ++i)
    {
        A[majorityIndex] == A[i] ? ++count : --count;
        if (count == 0)
        {
            majorityIndex = i;
            count = 1;
        }
    }
    return A[majorityIndex];
    
    /*if (A.size() == 1)        // My Solution which worked
        return A[0];
    vector<int> B(A);
    sort(B.begin(), B.end());
    int majority = 0;
    int count = 0;
    int ele = B[0];
    for (auto i = 1; i<B.size(); ++i)
    {
        if (B[i] == B[i-1])
        {
            ++count;
            if (count > majority)
            {
                majority = count;
                ele = B[i];
            }
        }
        else
            count = 0;
    }
    return ele;*/
}
