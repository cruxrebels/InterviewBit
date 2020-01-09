double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.empty())
        return (B.size()%2==0)? (B[B.size()/2]+B[B.size()/2-1])/2.0: B[B.size()/2];
    if(B.empty())
        return (A.size()%2==0)? (A[A.size()/2]+A[A.size()/2-1])/2.0: A[A.size()/2];
    if(A.size()>B.size())
        return findMedianSortedArrays(B,A);
    int n = A.size(), m= B.size();
    int start = 0,end = n,partitionX,partitionY,maxLeftX,maxLeftY,minRightX,minRightY;
    while(start<=end)
    {
        partitionX = (start+end)/2;
        partitionY = (n+m+1)/2 - partitionX;
        
        maxLeftX = (partitionX==0)?INT_MIN:A[partitionX-1];
        maxLeftY = (partitionY==0)?INT_MIN:B[partitionY-1];
        minRightX = (partitionX==n)?INT_MAX:A[partitionX];
        minRightY = (partitionX==m)?INT_MAX:B[partitionY];
        
        if(maxLeftX<=minRightY && maxLeftY<=minRightX)
        {
            //found
            if((n+m)%2==0)
                return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
            return (double)max(maxLeftX,maxLeftY);
        }
        else if(maxLeftX>minRightY)
            end = partitionX-1;
        else
            start = partitionX+1;
    }
}

