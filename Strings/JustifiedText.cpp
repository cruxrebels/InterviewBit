/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 Note: Each word is guaranteed not to exceed L in length. 
 
 https://www.interviewbit.com/problems/justified-text/
*/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    short int k = 0, ls = 0;
    for (short int i = 0; i<A.size(); i+=k)
    {
        /*string line = "";
        short int start = i;
        bool flag = false;*/
        
        k = ls = 0;
        while (i+k<A.size() && ls + k + A[i+k].size() <= B)
        {
            ls += A[i+k].size();
            ++k;
        }
        string tmp = A[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= A.size()) tmp += " ";
            else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');
        
        /*if (i+k==A.size())
        {
            flag = true;
            --i;
        }
            
        short int noOfGaps = i+k-1 - start; //auto noOfWords = (i+1)-start; auto noOfGaps = noOfWords-1; 
        short int spaces = B - ls;
        //int extraSpaces = spaces%noOfGaps;
        //int evenSpaces = spaces/noOfGaps;
        
        for (short int j = start; j <= i+k; ++j)
        {
            while (line.length() != B)
            {
                line += A[j];
                if (!flag) //middle lines
                {
                    if (j==start)
                        line += string((spaces/noOfGaps)+(spaces%noOfGaps), ' ');
                    else if (line.length() != B)
                        line += string((spaces/noOfGaps), ' ');
                }
                else
                {
                    line += " ";
                    if (j==i+k)
                        line += string(B-line.length(), ' ');
                }
            }
        }*/
        result.emplace_back(tmp);
    }
    return result;
}
