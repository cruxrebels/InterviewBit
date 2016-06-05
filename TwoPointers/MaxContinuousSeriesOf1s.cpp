/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

https://www.interviewbit.com/problems/max-continuous-series-of-1s/
*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int wL = 0, wR = 0; 
    int nZero = 0;
    int bestWindowWidth = -1;
    vector<int> result;
    int start = 0, end = 0;
    while (wR < A.size())
    {	
    	//expand to the right, update '0' count:
    	if (nZero <= B){
    		if (A[wR] == 0) 
    		    ++nZero; 
    		++wR;
    	}
    	
    	//shrink from left, update '0' count:
    	if (nZero > B){ 
    		if (A[wL] == 0) --nZero;
    		++wL;
    	}
    	
    	//update best window:
    	if (wR - wL + 1 > bestWindowWidth){
    		bestWindowWidth = wR - wL + 1;
    		start = wL;
    		end = wR;
    	}
    }
    for (auto i = start; i<end; ++i)
        result.emplace_back(i);
    return result;
}
