/*
N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated atleast one book.

NOTE: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

Input:
 List of Books M number of students 

Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 

https://www.interviewbit.com/problems/allocate-books/
*/

bool isPossible(const vector<int> A, int K, long long mid)
{
    long long total = 0; int cnt = 1;
    for (auto i = 0; i<A.size();)
    {
        if((long long)A[i] > mid) return false;
        if(total + (long long)A[i] > mid)
        {
            total = 0;
            cnt++;
        }
        else
        {
            total += (long long)A[i];
            i++;
        }
    }
    
    if(cnt <= K)
        return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size() < B) //Corner case
        return -1;
    long long low = *max_element(A.begin(), A.end());
    long long high = 0;
    for(auto i = 0; i<A.size(); ++i)
        high += (long long)A[i];
    long long ans = INT_MAX;
    ans *= INT_MAX;
    while (low<=high)
    {
        long long mid = low + (high - low)/2;
        if (isPossible(A, B, mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans%INT_MAX;
}
