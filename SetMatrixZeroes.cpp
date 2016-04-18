void Solution::setZeroes(vector<vector<int> > &A) {
    int nR = A.size();
    int nC = A[0].size();
    vector<int> r;
    vector<int> c;
    
    for(int i=0; i<nR; ++i)
    {
        for (int j=0; j<nC; ++j)
        {
            if (A[i][j] == 0)
            {
                if (find(r.begin(), r.end(), i) == r.end())
                    r.emplace_back(i);
                if (find(c.begin(), c.end(), j) == c.end())
                    c.emplace_back(j);
            }
        }
    }
    for (const auto& k : r)
    {
        for (int x=0; x<nC; ++x)
        {
            A[k][x] = 0;
        }
    }
    for (const auto& l : c)
    {
        for(int y=0; y<nR; ++y)
        {
            A[y][l] = 0;
        }
    }
}
