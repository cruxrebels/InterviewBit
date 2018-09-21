/*
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

https://www.interviewbit.com/problems/all-factors/
*/

// Solution 1
vector<int> Solution::allFactors(int A) {
    vector<int> result;
 
    for(auto i=1; i<=sqrt(A); ++i)
    {
        if(A%i==0)
        {
            result.emplace_back(i);
            if(i!=sqrt(A))
            {
                result.emplace_back(A/i);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Solution 2
vector<int> Solution::allFactors(int A) {
    if (A < 2)
        return { A };
    vector<int> result;
    vector<int> dividend;
    for (auto i = 1; i*i<=A; ++i)
    {
        if (A % i == 0)
        {
            result.emplace_back(i);
            int div = A / i;
            if (i != div)
            dividend.emplace_back(div);
        }
    }
    reverse(dividend.begin(), dividend.end());
    for (auto j = 0; j<dividend.size(); ++j)
        result.emplace_back(dividend[j]);
    return result;
}
