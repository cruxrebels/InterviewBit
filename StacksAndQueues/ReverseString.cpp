/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"

https://www.interviewbit.com/problems/reverse-string/
*/

string Solution::reverseString(string A) {
    stack<char> s;
    for (const auto& a : A) {
        s.push(a);
    }
    A.clear();
    while (!s.empty()) {
        A += s.top();
        s.pop();
    }
    return A;
}
