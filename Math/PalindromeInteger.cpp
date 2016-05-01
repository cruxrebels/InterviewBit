/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

https://www.interviewbit.com/problems/palindrome-integer/
*/

bool Solution::isPalindrome(int A) {
    if(A<0)
        return false;
    auto temp2 = A;    
    int sum = 0;

    while(temp2!=0)
    {
        int rem = temp2%10;
        //check for overflow while reversing
        if (sum > (INT_MAX / 10) || (sum == (INT_MAX / 10) && rem > (INT_MAX % 10))) 
            return false;
        sum = sum*10 + rem;
        temp2 /= 10;
    }
    return sum==A;
}
