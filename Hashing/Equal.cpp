/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.

https://www.interviewbit.com/problems/equal/
*/

vector<int> Solution::equal(vector<int> &A) {
    if (A.empty())
        return {};
    
    map<int, pair<int, int> > sum;
    vector<int> ans;
    auto size = A.size();
    
    for (auto i = 0; i<size; ++i)
    {
        for (auto j = i+1; j<size; ++j)
        {
            auto sumab = A[i] + A[j];
            
            if (sum.find(sumab) == sum.end())
                sum[sumab] = make_pair(i, j);
            else
            {
                pair<int, int> p = sum[sumab];

                if (p.first < i && p.second != i && p.second != j)
                {
                    vector<int> temp;
                    temp.emplace_back(p.first);
                    temp.emplace_back(p.second);
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    
                    if (ans.size() == 0)
                        ans = temp;
                    else
                    {
                        for (auto t = 0; t<ans.size(); ++t)
                        {
                            if (ans[t] < temp[t])
                                break;
                            if (ans[t] > temp[t])
                            {
                                ans.clear();
                                ans = temp;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
