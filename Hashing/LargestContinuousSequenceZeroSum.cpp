/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
See Expected Output

https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
*/

vector<int> Solution::lszero(vector<int> &A) {
    vector<int> seq;
    vector<int> sums;
    auto size = A.size();
    int sum = 0;
    unordered_map<int, int> hash;
    for (auto i = 0; i<size; ++i)
    {
        sum += A[i];
        sums.emplace_back(sum);
    }
    
    auto start = 0, end = 0;
    for (auto i = 0; i<size; ++i)
    {
        int temp_start, temp_end;
        if (sums[i] == 0)
        {
            temp_start = 0;
            temp_end = i+1;
            if (temp_end - temp_start >= end - start)
            {
                start = temp_start;
                end = temp_end;
            }
        }
        else
        {
            if (hash.find(sums[i]) != hash.end())
            {
                temp_start = hash[sums[i]] + 1;
                temp_end = i + 1;
                
                if (temp_end - temp_start > end - start)
                {
                    start = temp_start;
                    end = temp_end;
                }
                else if (temp_end - temp_start == end - start && start > temp_start)
                {
                    start = temp_start;
                    end = temp_end;
                }
            }
            else
                hash[sums[i]] = i;
        }
    }
    
    for (auto i = start; i<end; ++i)
        seq.emplace_back(A[i]);
    
    return seq;
}
