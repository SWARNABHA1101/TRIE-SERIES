//Problem link- https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>
struct Node{
  Node * links[2];
    bool containsKey(int idx){
        return (links[idx]!=NULL);
    }
    void put(int idx, Node * node){
        links[idx]=node;
    }
    Node * get(int idx){
        return links[idx];
    }
};

class Trie{
  private: Node * root;
    public:
    Trie(){
        root= new Node(); 
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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    vector<int>ans(queries.size(),0);
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<pair<int,pair<int,int>>>offlineQueries;
    int index=0;
    for(auto &it: queries){
        offlineQueries.push_back({it[1],{it[0],index++}});
    }
    sort(offlineQueries.begin(),offlineQueries.end());
    
    Trie trie;
    int i=0;
    for(auto &it: offlineQueries){
        while(i<n&&arr[i]<=it.first){
            trie.insert(arr[i]);
            i++;
        }
        if(i!=0)ans[it.second.second]=trie.findMax(it.second.first);
        else ans[it.second.second]=-1;
    }
    return ans;
}
