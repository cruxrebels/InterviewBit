vector<int> Solution::maxset(vector<int> &A) {
    long long maxsum = 0;
    long long cursum = 0;
    int startmax = -1;
    int endmax = -1;
    int start = 0;
    int end = 0;
    while(end<A.size())
    {
        if (A[end]>-1)
        {
            cursum += (long long)A[end];
            if (cursum>maxsum)
            {
                maxsum = cursum;
                startmax = start;
                endmax = end + 1;
            }
            else if (cursum==maxsum)
            {
                if(end+1-start > endmax-startmax)
                {
                    startmax = start;
                    endmax = end + 1;
                }
            }
        }
        else
        {
            cursum = 0;
            start = end + 1;
        }
        ++end;
    }
    vector<int> ans;
    ans.clear();
 
    if(startmax == -1 || endmax == -1)
        return ans;
 
    for(int i = startmax; i < endmax; ++i)
        ans.push_back(A[i]);
    return ans;
    
    //WHY DOES BELOW CODE COMPILES BUT THROWS Segmentation fault(Runtime error), invalid memory access?
    /*vector<vector<int> > B;
    vector<long long int> sum;
    int i = 0;
    for (auto it = 0; it<A.size(); ++it)
    {
        if(A[it]>-1)
        {
            B[i].emplace_back(A[it]);
        }
        else
        {
            while(A[it]<0 && it<A.size())
            {
                ++it;
            }
            --it;
            ++i;
        }    
    }
    
    //Debugging help
    /*for (auto z = 0 ; z<B.size(); ++z)
    {
        for ( auto y=0; y<B[z].size(); ++y)
            cout << B[z][y] << " ";
        cout << endl;
    }*/
    //Debugging help end
    
    /*for (int j = 0; j<B.size(); ++j)
    {
        accumulate(B[j].begin(), B[j].end(), sum[j]);
    }
    auto pos = max_element(sum.begin(), sum.end());
    
    return B[*pos];*/
}
