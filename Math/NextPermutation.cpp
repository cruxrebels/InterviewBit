/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

 Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of
 
https://www.interviewbit.com/problems/next-permutation/
*/

void mySwap(vector<int>& A, int i, int j) {
    int min = A[j], index = j;
    for (auto a = j; a < A.size(); ++a) {
        if (min > A[a] && A[a] > A[i]){ 
            min = A[a];
            index = a;
        }
    }
    swap(A[i], A[index]);
}

void Solution::nextPermutation(vector<int> &A) {
    int index = 0;
    bool desc = true;
    for (int i = A.size()-1; i > 0; --i) {
        if (A[i] > A[i-1]) {
            desc = false;
            mySwap(A, i-1, i);
            reverse(A.begin()+i, A.end());
            break;
        }
    }
    if (desc)
        reverse(A.begin(), A.end());
}
