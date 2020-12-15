class TrieNode {

  public:
    bool isLeaf;
    string word;            //not needed for this problem purpose though
    TrieNode* children[26];
  
    TrieNode(){
       isLeaf = false;
        word = "";
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
  
    
    void TrieAdd(string s){
        TrieNode* node = this;
        for(auto c:s){
            if(node->children[c-'a']==NULL){
               node->children[c-'a'] = new TrieNode(); 
            }
            node = node->children[c-'a'];
        }
        node->isLeaf = true;
        node->word = s;
    }
    
    
    
    bool TrieSearch(string s){
        //defines this as a root
        TrieNode* node = this;    
        for(auto c:s){
            if(node->children[c-'a']==NULL)
                return false;
            node = node->children[c-'a'];
        }
        return node->isLeaf;
    }
    
};


vector<int> Solution::solve(string A, vector<string> &B) {
    
    string word="";
    TrieNode* root = new TrieNode();
    
    //--------- Adding to Trie -----------
    for(auto c:A){
        if(c!='_'){
            word+=c;
        }
        else{
            root->TrieAdd(word);
            word="";
        }
    }
    //the last word
    root->TrieAdd(word);
    //-------------------------------------
    
    //------------ helper with Index -----
    vector<pair<string,int> > C;
    for(int i=0;i<B.size();i++){
        C.push_back(make_pair(B[i],i));
    }
    //------------------------------------
    
    //----------- Custom Sort ------------
    sort(C.begin(),C.end(),[&root](const pair<string,int> &sp, const pair<string,int> &rp){
                
        string word="",s = sp.first, r = rp.first;
        int count1=0,count2=0;
        //--------- search and count for s ----------
        for(auto c:s){
            if(c!='_'){
                word+=c;
            }
            else{
                if(root->TrieSearch(word)){
                    count1++;
                }
                word="";
            }
        }
        if(root->TrieSearch(word)){
            count1++;
        }
        word="";
        //------------------------------------------
        
        //--------- search and count for r ---------
        for(auto c:r){
            if(c!='_'){
                word+=c;
            }
            else{
                if(root->TrieSearch(word)){
                    count2++;
                }
                word="";
            }
        }
        if(root->TrieSearch(word)){
            count2++;
        }
        //------------------------------------------
        
        //return boolean result
        return count1 > count2 || (count2==count1 && sp.second<rp.second);
    });
    //--------------------------------------
    
    
    vector<int> ans;
    for(auto p:C){
        ans.push_back(p.second);
    }
    
    return ans;
}
