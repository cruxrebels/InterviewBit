/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    auto n = A.size();
    vector<int> res;
    //if (B>n)              // This check will also work
    //    return res;
    assert(B<=n);   // if false then write a error message to stdout & calls abort
    
    map<int, int> m;
    for (auto i = 0; i<n; ++i)
    {
        ++m[A[i]];
        
        if (i-B+1>=0)
        {
            res.emplace_back(m.size());
            --m[A[i-B+1]];
            if (m[A[i-B+1]] == 0)
                m.erase(A[i-B+1]);
        }
    }
    return res;
    
    // More verbose solution
    /*for (auto i = 0; i<B; ++i)
    {
        if (m[A[i]] == 0)
            ++c;
        m[A[i]] += 1;
    }
    res.emplace_back(c);
    
    for (auto i = B; i<n; ++i)
    {
        if (m[A[i-B]] == 1)
            --c;
        m[A[i-B]] -= 1;
        
        if (m[A[i]] == 0)
            ++c;
        m[A[i]] += 1;
        res.emplace_back(c);
    }
    return res;*/
}
