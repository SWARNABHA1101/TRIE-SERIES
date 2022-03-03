class Solution {
public:
   
        vector<string>ans;
        
        class Trie{
            public:
            Trie * links[26];
            bool flag=false;
            
        };
        void insert(string word, Trie * root){
            Trie * node=root;
            for(int i=0;i<word.length();++i){
                if(node->links[word[i]-'a']==NULL)node->links[word[i]-'a']=new Trie();
                node=node->links[word[i]-'a'];
            }
            node->flag=true;
        }
        
        bool search(string word,Trie * root ){
            Trie * node=root;
            for(int i=0;i<word.length();++i){
                if(node->links[word[i]-'a']==NULL)return false;
                node=node->links[word[i]-'a'];
            }
            return node->flag;
        }
    
    void dfs(string&s,int idx,Trie * root,string currStr){
        if(idx==s.size()){
            ans.push_back(currStr.substr(0,currStr.size()-1));
            return;
        }
        string str="";
        for(int i=idx;i<s.size();++i){
            str.push_back(s[i]);
            if(search(str,root))dfs(s,i+1,root,currStr+str+" ");
        }
        
    }
     vector<string> wordBreak(string s, vector<string>& wordDict) {
         Trie * root=new Trie();
         for(auto &it: wordDict){
             insert(it,root);
             
         }
         dfs(s,0,root,"");
         return ans;
     }
};
