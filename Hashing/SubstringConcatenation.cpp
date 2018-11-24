/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without 
any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

https://www.interviewbit.com/problems/substring-concatenation/
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int noOfWords = B.size();
    vector<int> res;
    if (A.size() == 0 || B.size() == 0){
        return res;
    }
    
    int wordSize = B[0].size();
    unordered_map<string, int> hash;
    
    for (const auto& b : B)
        ++hash[b];
    
    auto i = 0;
    while ((i + wordSize*noOfWords - 1) < A.size()) {
        unordered_map<string, int> tempHash;
        auto j = 0;
        while (j < A.size()) {
            string word = A.substr(i + j*wordSize, wordSize);
            if (hash.find(word) == hash.end()) {
                break;
            } else {
                if (++tempHash[word] > hash[word]){
                    break;
                }
                ++j;
            }
            
            if (j == noOfWords)
                res.emplace_back(i);
        }
        ++i;
    }
    
    return res;
}

// Initial solution approach which failed for '1 Submission test case.
/*vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int noOfWords = B.size();
    if (!noOfWords)
        return {};
    int wordSize = B[0].size();
    if (wordSize > A.length())
        return {};
        
    unordered_map<string, int> hasToBeFound;
    unordered_map<string, int> found;
    vector<int> res;
    int count = 0;
    
    for (const auto& b : B)
        ++hasToBeFound[b];

    for (auto i = 0; i <= A.size(); ++i) {
        if (count == noOfWords*wordSize) {
            found.clear();
            i = i - noOfWords*wordSize;
            res.emplace_back(i);
            ++i; count = 0;
        }
        string word = A.substr(i, wordSize);
        if (word.length() < wordSize)
            break;
        if (hasToBeFound.find(word) == hasToBeFound.end()) {
            found.clear();
            count = 0;
            continue;
        }
        
        if (++found[word] <= hasToBeFound[word]) {
            i += wordSize-1;    // since for loop is incrementing i too
            count += wordSize;
        } else {
            found.clear();
            count = 0;
        }
    }
    return res;
}*/
