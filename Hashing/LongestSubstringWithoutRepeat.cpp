/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int Solution::lengthOfLongestSubstring(string A) {
    if (A.empty())
        return 0;
    
    unordered_map<char, int> ls;
    int count = 0;
    int ans = 0;
    
    auto q = 0;
    auto size = A.size();
    
    while (q<size)
    {
        if (ls.find(A[q]) == ls.end())
        {
            ls[A[q]] = q;
            ++count; ++q;
        }
        else
        {
            q = ls[A[q]] + 1;
            ls.clear();
            ans = max(count, ans);
            count = 0;
        }
    }
    ans = max(count, ans);
    
    return ans;
}
