/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

https://www.interviewbit.com/problems/palindrome-string/
*/

int Solution::isPalindrome(string A) {
    int i = 0, j = A.length()-1;
    while (i<j)
    {
        while(i<j && !isalnum(A[i])) i++;
        while(i<j && !isalnum(A[j])) j--;
        if(tolower(A[i])!=tolower(A[j]))
            return 0;
        i++; j--;
    }
    return 1;
}
