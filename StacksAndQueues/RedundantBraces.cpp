/*
Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a+b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

https://www.interviewbit.com/problems/redundant-braces/
*/

int Solution::braces(string A) {
    stack<char> s;
    auto size = A.length();
    auto i = 0;
    while(i<size)
    {
        char c = A[i];
        if (c == '(' || c == '+' || c == '*' || c == '-' || c == '/')
            s.push(c);
        else if (c == ')')
        {
            if (s.top() == '(')
                return 1;
            else
            {
                while (!s.empty() && s.top() != '(')
                    s.pop();
                s.pop();
            }
        }
        ++i;
    }
    return 0;
}
