/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

https://www.interviewbit.com/problems/fraction/
*/

string Solution::fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return "0";
    int64_t n = numerator, d = denominator;
    string res = "";
    
    if (n < 0 ^ d < 0)      //Brilliant
        res += '-';
    
    n = abs(n), d = abs(d);
    
    res += to_string(n/d);
    int64_t rem = n%d;
    
    if (rem == 0)
        return res;
    
    res += '.';
    
    unordered_map<int, int> m;
    
    for (; rem; rem %= d)
    {
        if (m.find(rem) != m.end())
        {
            res.insert(m[rem], 1, '(');
            res.push_back(')');
            break;
        }
        
        m[rem] = res.size();
        rem *= 10;
        res.push_back('0' + rem/d);
    }
    return res;
    
    /*if (numerator == 0)       //traditional brute force does not works.
        return "0";
    if (denominator == 0)
        return "";
    long double res = numerator/(long double)denominator;
    cout  << res << "\n";
    
    string resStr = to_string(res);
    cout << stold(resStr) << "\n";
    int found = resStr.find('.');
    
    auto it = resStr.begin()+found+1;
    for (; it != resStr.end()-1; ++it)
    {
        if (*it != *(it+1))
            break;
    }
    cout << it - resStr.begin()+found+1 << "\n";
    cout << resStr.end()-1 - resStr.begin()+found+1 << "\n";
    cout << resStr.length()-1 << "\n";
    if (it == resStr.end()-1)
    {
        resStr.insert(resStr.begin()+found+1, '(');
        resStr.insert(resStr.begin()+found+3, ')');
        resStr.erase(found+4);
    }
    return resStr;*/
}
