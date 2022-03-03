class Node{
    public:
    Node * links[10];
    bool flag=false;
    int data=-1;
    
    
    bool containsKey(char ch){
        return (links[ch-'0']!=NULL);
    }
    Node * get(char ch){
        return links[ch-'0'];
    }
    void put(char ch, Node * node){
        links[ch-'0']=node;
    }
    bool setEnd(){
       return flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Solution {
 
private:
    Node * root;
public:
    
    vector<int>ans;
    Solution(){
        root=new Node();
    }
    void insert(int num){
        string s=to_string(num);
        Node * node=root;
        for(int i=0;i<s.size();++i){
            if(!node->containsKey(s[i])){
                node->put(s[i],new Node());
            }
            node=node->get(s[i]);
        }
        node->data=num;
        node->setEnd();
    }
    void print(Node * root){
        Node * node=root;
        if(root->flag){
            ans.push_back(root->data);
        }
        for(int i=0;i<10;++i){
            if(root->links[i]){
                print(root->links[i]);
            }
        }
    }
public:

    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=n;++i)
            insert(i);
            print(root);
        
        return ans;
        
    }
};
