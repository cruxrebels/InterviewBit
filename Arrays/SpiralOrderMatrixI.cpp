vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int rows = A.size();
    if (rows == 0)
	    return vector<int>();
    int cols = A[0].size();
    vector<int> result;
    result.resize(rows*cols);
	// DO STUFF HERE AND POPULATE result
    int l = 0, t = 0, r = cols-1, b = rows-1;
    int dir = 0;
    int n = -1;
    while (t<=b && l<=r)
    {
        switch (dir)
        {
            case 0:
                for (auto i = l; i<=r; ++i)
                    result[++n] = A[t][i];
                ++t; dir = 1;
                break;
            case 1:
                for (auto i = t; i<=b; ++i)
                    result[++n] = A[i][r];
                --r; dir = 2;
                break;
            case 2:
                for (auto i = r; i>=l; --i)
                    result[++n] = A[b][i];
                --b; dir = 3;
                break;
            case 3:
                for (auto i = b; i>=t; --i)
                    result[++n] = A[i][l];
                ++l; dir = 0;
                break;
        }
    }
    return result;
}
