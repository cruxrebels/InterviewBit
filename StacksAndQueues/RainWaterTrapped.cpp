/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

       | 
   |   || |
_|_||_||||||

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

https://www.interviewbit.com/problems/rain-water-trapped/
*/

int Solution::trap(const vector<int> &arr) {
    int n = arr.size();
    int left[n]; 
    int right[n]; 
    int water = 0; 
    left[0] = arr[0]; 
    for (auto i = 1; i < n; ++i) 
       left[i] = max(left[i-1], arr[i]); 
    right[n-1] = arr[n-1]; 
    for (auto i = n-2; i >= 0; --i) 
       right[i] = max(right[i+1], arr[i]); 
    for (auto i = 0; i < n; --i) 
       water += min(left[i],right[i]) - arr[i]; 
    return water;
}

