struct Node{
  Node * links[2];
    
    bool containsKey(int idx){
        return (links[idx]!=NULL);
    }
    Node * get(int idx){
        return links[idx];
    }
    void put(int idx,Node * node){
        links[idx]=node;
    }
    
};

class Trie{
 private: Node * root;
 public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node * node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int findMax(int num){
        Node * node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(!bit)){
                maxNum=maxNum|(1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
    
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here. 
    Trie trie;
    for(int i=0;i<n;++i){
        trie.insert(arr1[i]);
    }
    int maxi=0;
    for(int i=0;i<m;++i){
        maxi=max(maxi,trie.findMax(arr2[i]));
    }
    return maxi;
}
