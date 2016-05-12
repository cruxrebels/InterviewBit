/*
Please Note:

Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

https://www.interviewbit.com/problems/implement-strstr/
*/

int Solution::strStr(const string &haystack, const string &needle) {
    int index = -1;
    if (haystack.empty() || needle.empty())
        return index;
    for (auto i = 0; i<haystack.length(); ++i)
    {
        if (haystack[i]==needle[0])
        {
            index = i;
            int j = 0;
            while (j<needle.length())
            {
                if (needle[j]==haystack[i] && i<haystack.length())
                {
                    ++i; ++j;
                }
                else
                {
                    index = -1;
                    i -= j;
                    break;
                }
            }
            if (j==needle.length())
                return index;
        }
    }
    return index;
}
