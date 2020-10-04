/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. 
Return its length: 4.

Your algorithm should run in O(n) complexity.

https://www.interviewbit.com/problems/longest-consecutive-sequence/
*/


int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s;

    for(auto i : A)
        s.insert(i);
 
    int ans = 0;
    for(auto i : A){
        if(s.find(i-1) == s.end()){
            int j = i;
            while(s.find(j) != s.end())
                j++;
            ans = max(ans, j-i);
        }
    }

    return ans;
}
