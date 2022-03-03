
struct Node{
  
    Node * links[2];
    int cnt=0;
    
    bool containsKey(int idx){
        return links[idx]!=NULL;
    }
    void put(int idx, Node * node){
        links[idx]=node;
    }
    Node * get(int idx){
        return links[idx];
    }
    void setCount(int idx){
        links[idx]->cnt++;
    }
    int getCount(int idx){
        return links[idx]->cnt;
    }
};

class Solution {
public:
    Node * root=new Node();
    
    void insert(int num){
        Node * node=root;
        
        for(int i=15;i>=0;i--){
            int bitVal=(bool)(num&(1<<i));
            
            if(!node->containsKey(bitVal)){
                node->put(bitVal,new Node());
            }
            node->setCount(bitVal);
            node=node->get(bitVal);
        }
    }
    
    int getPairs(int num,int k){
        Node * node=root;
        
        int cntPairs=0;
        
        for(int i=15;i>=0&&node;i--){
            int bit_num=(bool)(num&(1<<i));
            int bit_k=(bool)(k&(1<<i));
            
            if(bit_k){
                if(node->containsKey(bit_num)){
                    cntPairs+=node->getCount(bit_num);
                }
                if(node->containsKey(!bit_num)){
                    node=node->get(!bit_num);
                }
                else break;
            }
            else if(node->containsKey(bit_num)){
                node=node->get(bit_num);
            }
            else{
                break;
            }
        }
        return cntPairs;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        int cnt=0;
        
        for(int i=0;i<n;++i){
            cnt+=getPairs(nums[i],high+1)-getPairs(nums[i],low);
            insert(nums[i]);
        }
        return cnt;
    }
};
