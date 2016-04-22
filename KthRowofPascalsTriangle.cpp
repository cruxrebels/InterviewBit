vector<int> Solution::getRow(int A) {
    vector<pair<int, int> > search_space;
    vector<vector<int> > result;
    for (auto s = 0; s<=A; ++s)
    {
        search_space.emplace_back(make_pair(s, s+1));
    }
    
    for (auto i = 0; i<search_space.size(); ++i)
    {
        int x = search_space[i].first;
        int y = search_space[i].second;
        vector<int> temp;
        while(y!=0)
        {
            if(y==1)
            {
                temp.emplace_back(1);
                --y;
                break;
            }
            else if(y==2)
            {
                temp.emplace_back(1);
                temp.emplace_back(1);
                y -= 2;
                break;
            }
            else
            {
                int t = y;
                temp.emplace_back(1);
                --y;
                for (int c=1; c<t-1; ++c)
                {
                    auto value = result[x-1][c-1] + result[x-1][c];
                    temp.emplace_back(value);
                    --y;
                }
                temp.emplace_back(1);
                --y;
            }
        }
        result.emplace_back(temp);
    }
    return result[A];
}
