/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

https://www.interviewbit.com/problems/simplify-directory-path/
*/

string Solution::simplifyPath(string A) {
  stack<char> s;
  auto size = A.length();
  
  for (auto i = 0; i<size; ++i)
      s.push(A[i]);
  
  while(!s.empty() && !isalpha(s.top()))
      s.pop();
      
  if(s.empty())
      return "/";
  A.clear();
  bool flag = false;
  while(!s.empty() && (isalpha(s.top()) || s.top()=='/'))
  {
      if(s.top()=='/')
          flag = true;
      else
      {
          if(flag)
          {
              A += '/';
              flag = false;
          }
          A += s.top();   
      }
          
      s.pop();
      //cout << s.top() << "\n";
  }
  A += '/'; //cout << s.top() << "\n"; cout << A << "\n";cout << A.length() << "\n";
  string result = "";
  for (int j = A.length()-1; j>-1; --j)
      result += A[j]; 
  return result;
}
