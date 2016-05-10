/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.

https://www.interviewbit.com/problems/longest-common-prefix/
*/
string Solution::longestCommonPrefix(vector<string> &A) {
    string result = "";
    auto n = A.size();
    int j = INT_MAX;
    for (auto i = 0; i<n; ++i)
    {
        auto s = A[i].length();
        if (j > s)
            j = s;
    }
    
    for (auto i = 0; i<j; ++i)
    {
        auto temp = A[0][i];
        int k = 1;
        while (k<n)
        {
            if (temp==A[k][i])
                ++k;
            else
                return result;
        }
        result += temp; 
    }
    return result;
}
