/*
There is a row of seats. Assume that it contains N seats adjacent to each other. 
There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, 
without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement
    
https://www.interviewbit.com/problems/seats/
*/

#define MOD 10000003
int Solution::seats(string A) {
    auto n = A.length();
    
    // Median approach
    vector<int> pos;
    for (auto i = 0; i<n; ++i)
        if (A[i] == 'x')
            pos.emplace_back(i);
    
    auto psize = pos.size();
    
    if (psize == 0)
        return 0;
    int mid = psize/2;
    int median = psize & 1 ? pos[mid] : (pos[mid-1] + pos[mid])/2;
    
    int hops = 0; 
    int empty = A[median] == 'x' ? median - 1 : median;
    
    for (auto s = median-1; s>=0; --s)
        if (A[s] == 'x')
        {
            hops += empty - s;
            hops %= MOD;
            --empty;
        }
            
    empty = median + 1;
    for (auto e = median+1; e<n; ++e)
        if (A[e] == 'x')
        {
            hops += e - empty;
            hops %= MOD;
            ++empty;
        }
    
    return hops % MOD;
    
    // My attempt of pushing it near max x count - failed for corner cases
    /*int maxCount = INT_MIN, startIndex = 0, endIndex = 0;
    int hops = 0;
    for (auto i = 0; i < n; ++i)
    {
        int count = 0, index = i;
        while (A[i] == 'x' && i < n)
        {
            ++count;
            ++i;
        }
        if (count > maxCount)
        {
            maxCount = count;
            startIndex = index;
            endIndex = i - 1;
        }
    }
    cout << maxCount << " " << startIndex << endIndex << endl;
    auto f1 = startIndex, f2 = endIndex;
    for (auto j = 0; j < n; ++j)
    {
        if (A[j] == 'x' && !(j >= f1 && j <= f2))
        {
            int d1 = abs(startIndex - 1 - j);
            int d2 = abs(endIndex + 1 - j);
            if (d1<=d2)
                if (startIndex > 0)
                    --startIndex;
            else
                if (endIndex < n-1)
                    ++endIndex;
            hops += min (d1, d2);
        }
    }
    return hops % 10000003;*/
}
