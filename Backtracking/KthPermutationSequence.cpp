/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

 Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
> In this case, just concatenate the number to the answer.
> so if n = 11, k = 1, ans = "1234567891011"
Whats the maximum value of n and k?
> In this case, k will be a positive integer thats less than INT_MAX.
> n is reasonable enough to make sure the answer does not bloat up a lot.

https://www.interviewbit.com/problems/kth-permutation-sequence/
*/

int fact(int n)
{
    if (n>12)   
        return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i)
        f *= i;
    return f;
}
string backtracking(int k, vector<int>& numlist)
{
    auto n = numlist.size();
    if (n==0 || k > fact(n))
        return "";
    int f = fact(n-1);
    int pos = k / f;
    k %= f;
    string ch = to_string(numlist[pos]);
    numlist.erase(numlist.begin() + pos);
    return ch + backtracking(k, numlist);
}
string Solution::getPermutation(int n, int k) {
    vector<int> numlist;
    
    for (auto i = 1; i<n+1; ++i)
        numlist.emplace_back(i);
    return backtracking(k-1, numlist);
}
