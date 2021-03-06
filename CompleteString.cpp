//Problem Statement- https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos


struct Node{
  
    Node * links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node * node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};

class Trie{
private: Node * root;
public: 
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node * node=root;
        for(int i=0;i<word.length();++i){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfAllPrefixExist(string word){
        Node * node=root;
        bool flag=true;
        for(int i=0;i<word.length();++i){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                flag = flag & node->isEnd();  //or(if(isEnd==false))return false
            }
            else{
                return false;
            }
        }
        return flag;
    }
    
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    string ans="";
    Trie * obj=new Trie();
    for(auto &it: a)obj->insert(it);
    for(auto &it:a){
        if(obj->checkIfAllPrefixExist(it)){
            if(it.size()>ans.size()){
                ans=it;
            }
            else if(it.size()==ans.size()&&it<ans){ //equal and check lexico smallest
                ans=it;
            }
        }
    }
    
    
    if(ans=="")return "None";
    return ans;
    
}
