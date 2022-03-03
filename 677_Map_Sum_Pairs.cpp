class Node{
    
    public:
    Node * links[26];
    
    int score=0;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node * get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node * node){
        links[ch-'a']=node;
    }
};

class MapSum {
private:
    Node * root;
    
    
   public: 
    int ans=0;
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        Node * node=root;
        for(int i=0;i<key.length();++i){
            if(!node->containsKey(key[i])){
                node->put(key[i],new Node());
            }
            node=node->get(key[i]);
        }
        node->score=val;
        
    }
    
    int sum(string prefix) {
       ans=0;
        Node * node=root;
        for(int i=0;i<prefix.length();++i){
            if(!node->containsKey(prefix[i]))
                return 0;
            node=node->get(prefix[i]);
            }
        solve(node);
        return ans;
    }
    void solve(Node * node){
        ans+=node->score;
        for(int i=0;i<26;++i){
            if(node->links[i]){
                solve(node->links[i]);
            }
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
