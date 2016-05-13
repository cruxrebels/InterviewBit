/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20

https://www.interviewbit.com/problems/roman-to-integer/
*/

int romanCharToInt(char c)
{
    switch(c)
    {
        case 'I':
        case 'i':
            return 1;
        case 'V':
        case 'v':
            return 5;
        case 'X':
        case 'x':
            return 10;
        case 'L':
        case 'l':
            return 50;
        case 'C':
        case 'c':
            return 100;
        case 'D':
        case 'd':
            return 500;
        case 'M':
        case 'm':
            return 1000;
        default:
            return 0;
    }
}
int Solution::romanToInt(string A) {
    int result = 0;
    int n = A.length();
    
    for (auto i = 0; i<n; ++i)
    {
        if (i!=n && romanCharToInt(A[i]) < romanCharToInt(A[i+1]))
            result -= romanCharToInt(A[i]);
        else 
            result += romanCharToInt(A[i]);
    }
    return result;
}
/*int Solution::romanToInt(string A) { //Brute force approach repetitive code
    int result = 0;
    int n = A.length();
    
    for (auto i = 0; i<n; ++i)
    {
        switch(A[i])
        {
            case 'I':
            case 'i':
                if (toupper(A[i+1])=='V' && i+1 != n)
                {   result += 4; i++; break; }
                else if (toupper(A[i+1])=='X' && i+1 != n)
                {   result += 9; i++; break; }
                else
                {
                    result += 1;
                    break;
                }
            case 'V':
            case 'v':
                result += 5;
                break;
            case 'X':
            case 'x':
                if (toupper(A[i+1])=='L' && i+1 != n)
                {   result += 40; i++; break; }
                else if (toupper(A[i+1])=='C' && i+1 != n)
                {   result += 90; i++; break; }
                else
                {
                    result += 10;
                    break;
                }
            case 'L':
            case 'l':
                result += 50;
                break;
            case 'C':
            case 'c':
                if (toupper(A[i+1])=='D' && i+1 != n)
                {   result += 400; i++; break; }
                else if (toupper(A[i+1])=='M' && i+1 != n)
                {   result += 900; i++; break; }
                else
                {
                    result += 100;
                    break;
                }
            case 'D':
            case 'd':
                result += 500;
                break;
            case 'M':
            case 'm':
                result += 1000;
                break;
            default:
                break;
        }
    }
    return result;
}
*/ //Brute force approach repetitive code
