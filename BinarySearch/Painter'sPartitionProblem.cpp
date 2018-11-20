/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much
time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that
any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50

https://www.interviewbit.com/problems/painters-partition-problem/
*/

bool isPossible(long long _Max, int K, vector<int> &arr) {
             
    int _max_ele = *max_element(arr.begin(), arr.end());
    if(_max_ele > _Max)
            return false; 
             
    long long Sum = 0;
    int cnt = 1;
    int N = arr.size();
 
    for(int i = 0; i < N;) {
        if(Sum + ((long long)arr[i]) > _Max) {
            Sum = 0;
            cnt++;
        } else {
            Sum += ((long long)arr[i]);
            i++;
        }
    }
 
    if(cnt <= K) return true;
    return false;
}
 
int Solution::paint(int A, int B, vector<int> &C) {    
    int N = C.size();
             
    long long end = 0;
    long long start = 0;
 
    for(int i = 0; i < N; ++i) {
        end += C[i];
    }
     
    long long ans = INT_MAX;
    ans *= INT_MAX;
    while(start <= end) {
         
        long long mid = (start + end) / 2;
        if(isPossible(mid, A, C)) {
            ans = min(ans, mid);
            end = mid - 1;
        } 
        else {
            start = mid + 1;
        }
    }
             
    return (ans * (long long) B) % 10000003;
}

// Solution 2 - Easier to understand but gives TLE on InterviewBit OJ

/*int getMax(const vector<int>& C, int t) {
  int max = INT_MIN;
  for (auto i = 0; i < t; ++i) {
     if (C[i] > max) max = C[i];
  }
  return max%10000003;
}

int sum(const vector<int>& C)
{
    long long total = 0;
    for (auto i = 0; i<C.size(); ++i)
        total += C[i];
    return (int)total%10000003;
}

int requiredPainters(const vector<int>& C, int t, long long maxLengthPerPainter)
{
    long long total = 0, numOfPainters = 1;
    for(auto i = 0; i<t; ++i)
    {
        total += C[i];
        if(total>maxLengthPerPainter)
        {
            total = C[i];
            numOfPainters++;
        }
    }
    return numOfPainters%10000003;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long low = getMax(C, B);    
    long long high = sum(C);
    
    while(low<=high)
    {
        long long mid = low + (high-low)/2;
        int numPainters = requiredPainters(C, B, mid);
        
        if(numPainters<=A)
            high = mid;
        else
            low = mid + 1;
    }
    return (int)low%10000003;
}*/
