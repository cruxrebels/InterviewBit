/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

https://www.interviewbit.com/problems/length-of-last-word/
*/

int Solution::lengthOfLastWord(const string &A) {
    int result = 0;
    int cnt = 0;
    auto i = 0;
    while (i<A.length())
    {
        cnt = 0;
        while (A[i] != ' ')
        {   
            ++cnt;
            if(A[i+1] == '\0')
                return cnt;
            else if (A[i+1]== ' ')
                result = cnt;
            ++i;
        }
        ++i;
    }
    return result;
}
