/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")

https://www.interviewbit.com/problems/palindrome-partitioning/
*/

bool isPalindrome(const string s, int i, int j)
{
    while (i<j)
    {
        if (s[i] == s[j])
        {
            ++i; --j;
        }
        else
            return false;
    }
    return true;
}

void backtracking(const string& s, int i, vector<string>& row, vector<vector<string> >& res)
{
    if (i == s.length())
    {
        res.emplace_back(row); 
        return;
    }
       
    for (auto x = i; x < s.length(); ++x)
    {        
        if (isPalindrome(s, i, x))
        {
            row.emplace_back(s.substr(i, x-i+1));
            backtracking(s, x+1, row, res);
            row.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<string> row;
    vector<vector<string> > res;
    backtracking(A, 0, row, res);
    return res;
}
