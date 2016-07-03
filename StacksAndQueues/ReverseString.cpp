/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"

https://www.interviewbit.com/problems/reverse-string/
*/

string Solution::reverseString(string A) {
    stack<char> s;
    auto size = A.length();
    
    for(auto i=0; i<size; ++i)
        s.push(A[i]);
    A.clear();
    for(auto j=0; j<size; ++j)
    {
        if(!s.empty())
        {
            A += s.top();
            s.pop();
        }
    }
    return A;
}

/*string Solution::reverseString(string A) {
    stack<char> s;
    auto size = A.length();
    
    for(auto i=0; i<size; ++i)
        s.push(A[i]);
    A.clear();  //Not necessarily required since the new string length is going to be the same. See above approach.
    for(auto j=0; j<size; ++j)
    {
        if(!s.empty())
        {
            A += s.top();   //One way to do it
            s.pop();
        }
    }
    return A;
}*/
