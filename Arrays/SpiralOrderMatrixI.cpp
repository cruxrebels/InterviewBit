vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	auto rows = A.size
	if (rows == 0)
	    return vector<int> ();
	auto columns = A[0].size();
	int T, B, L, R;
	T = 0, B = rows - 1, L = 0, R = columns - 1;
	int dir = 0;
	while(T<=B && L<=R)
	{
	    switch(dir)
	    {
	        case 0: 
	        for(auto i=L; i<=R; ++i)
	        {
	            result.emplace_back(A[T][i]);
	        }
	        T++;
	        break;
	        
	        case 1:
	        for(auto j=T; j<=B; ++j)
	        {
	            result.emplace_back(A[j][R]);
	        }
	        R--;
	        break;
	        
	        case 2:
	        for(auto k=R; k>=L; --k)
	        {
	            result.emplace_back(A[B][k]);
	        }
	        B--;
	        break;
	        
	        case 3:
	        for(auto l=B; l>=T; --l)
	        {
	            result.emplace_back(A[l][L]);
	        }
	        L++;
	        break;
	        
	        default:
	        std::cout<<"Inside default\n";
	        break;
	    }
	    dir = (dir + 1)%4;
	}
	return result;
}
