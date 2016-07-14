/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/

void backtracking(int n, int open, int close, string str, vector<string>& res)
{
    if (close == n)
    {
        res.emplace_back(str);
        return;
    }
    else
    {
        if (open < n)
        { 
            str += '(';
            backtracking(n, open+1, close, str, res);
            str.pop_back();
        }
        if (open > close)
        {
            str += ')';
            backtracking(n, open, close+1, str, res);
            str.pop_back();
        }
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    
    if (A>0)
        backtracking(A, 0, 0, "", res);
    return res;
}
