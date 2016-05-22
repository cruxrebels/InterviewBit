/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.

https://www.interviewbit.com/problems/atoi/
*/

//My naive brute force approach
/*int Solution::atoi(const string &A) {
    int i = 0;
    int result = 0;
    bool space = false;
    bool neg = false;
    
    while(i<A.length())
    {
        if(A[i]==' ')
        {
            if(isdigit(A[i-1]))
                space = true;
            ++i;
        }
        else if(A[i]=='-' && isdigit(A[i+1]))
        {
            neg = true;
            ++i;
        }
        else if(!isdigit(A[i]) && A[i] != ' ' && !isdigit(A[i+1]))
            return result;
        else if (isalpha(A[i]))
        {
            if(neg)
                result *= -1;
            return result;
        }
        else if(isdigit(A[i]))
        {
            if(space)
            {
                if(neg)
                    result *= -1;
                return result;
            }
            int temp = A[i] - '0';
            if(result>(INT_MAX/10) || (result==(INT_MAX/10) && temp>(INT_MAX%10)))
            {
                if(neg)
                    return INT_MIN;
                return INT_MAX;
            }
            result = result*10 + temp;
            ++i;
        }
        else 
            ++i;
    }
    if(neg)
        result *= -1;
    return result;
}*/

//Editorial Solution
class Solution {
    public:
        int atoi(const string &str) {
            int sign = 1, base = 0, i = 0;
            while (str[i] == ' ') { i++; }
            if (str[i] == '-' || str[i] == '+') {
                sign = (str[i++] == '-') ? -1 : 1; 
            }
            while (str[i] >= '0' && str[i] <= '9') {
                if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                base  = 10 * base + (str[i++] - '0');
            }
            return base * sign;
        }
};
