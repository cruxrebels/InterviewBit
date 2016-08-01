/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within 
 
 https://www.interviewbit.com/problems/anagrams/
 */
 
 vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > res;
    vector<string> row;
    unordered_map<string, vector<int> > anagram;
    auto size = A.size();
    
    for (auto i = 0; i<size; ++i)
    {
        string temp;
        temp.append(A[i]);
        sort(temp.begin(), temp.end());
        row.emplace_back(temp);
    }
    
    for (auto j = 0; j<size; ++j)
        anagram[row[j]].emplace_back(j+1);
    
    for (auto it = anagram.begin(); it != anagram.end(); ++it)
        res.emplace_back(it->second);
    
    return res;
}
